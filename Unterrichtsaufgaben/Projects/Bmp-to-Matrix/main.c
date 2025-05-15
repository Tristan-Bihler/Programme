#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For uint16_t, uint32_t, int32_t
#include <string.h> // For strlen, fgets

// Note on structure packing:
// The #pragma pack directives are typically used with MSVC.
// For GCC/Clang, you would use __attribute__((packed)) on each struct definition, e.g.:
// typedef struct __attribute__((packed)) { ... } BMPFileHeader;

#if defined(_MSC_VER)
#pragma pack(push, 1) // Exact fit for structure members, no padding
#endif

// BMP File Header structure (14 bytes)
// Contains information about the BMP file.
typedef struct {
    uint16_t bfType;      // Signature: "BM" (0x4D42). Identifies the file as a BMP.
    uint32_t bfSize;      // File size in bytes.
    uint16_t bfReserved1; // Reserved; must be 0.
    uint16_t bfReserved2; // Reserved; must be 0.
    uint32_t bfOffBits;   // Offset from the beginning of the file to the pixel data.
} BMPFileHeader;

// BMP Info Header structure (BITMAPINFOHEADER - 40 bytes)
// Contains information about the image dimensions and color format.
typedef struct {
    uint32_t biSize;          // Header size in bytes (should be 40 for BITMAPINFOHEADER).
    int32_t  biWidth;         // Image width in pixels.
    int32_t  biHeight;        // Image height in pixels.
                              // Positive: bottom-up image (first scan line is the last).
                              // Negative: top-down image (first scan line is the first).
    uint16_t biPlanes;        // Number of color planes (must be 1).
    uint16_t biBitCount;      // Bits per pixel (e.g., 1, 4, 8, 24, 32). This code handles 24.
    uint32_t biCompression;   // Compression type (0 for BI_RGB, i.e., uncompressed).
    uint32_t biSizeImage;     // Image size in bytes (can be 0 for uncompressed BI_RGB).
    int32_t  biXPelsPerMeter; // Horizontal resolution (pixels per meter).
    int32_t  biYPelsPerMeter; // Vertical resolution (pixels per meter).
    uint32_t biClrUsed;       // Number of colors in the palette (0 means 2^biBitCount).
    uint32_t biClrImportant;  // Number of important colors (0 means all are important).
} BMPInfoHeader;

#if defined(_MSC_VER)
#pragma pack(pop) // Restore default packing
#endif

// Function to free the dynamically allocated 2D matrix
void free_matrix(int **matrix, int height) {
    if (matrix == NULL) {
        return;
    }
    for (int i = 0; i < height; ++i) {
        free(matrix[i]); // Free each row
    }
    free(matrix); // Free the array of row pointers
}

int main() { // Removed argc, argv
    char filename[256]; // Buffer to store the filename

    // Prompt user for filename
    printf("Enter the path to the BMP file: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading filename.\n");
        return 1;
    }

    // Remove trailing newline character from fgets, if present
    filename[strcspn(filename, "\n")] = 0;
    // Also remove potential carriage return for Windows CRLF newlines
    filename[strcspn(filename, "\r")] = 0;


    FILE *file = fopen(filename, "rb"); // Open in binary read mode
    if (!file) {
        perror("Error opening file");
        fprintf(stderr, "Filename attempted: '%s'\n", filename);
        return 1;
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;

    // Read BMP File Header
    if (fread(&file_header, sizeof(BMPFileHeader), 1, file) != 1) {
        fprintf(stderr, "Error reading BMP file header.\n");
        fclose(file);
        return 1;
    }

    // Validate BMP signature ("BM")
    if (file_header.bfType != 0x4D42) { // 0x4D42 is 'BM' in little-endian
        fprintf(stderr, "Not a valid BMP file (invalid signature).\n");
        fclose(file);
        return 1;
    }

    // Read BMP Info Header
    if (fread(&info_header, sizeof(BMPInfoHeader), 1, file) != 1) {
        fprintf(stderr, "Error reading BMP info header.\n");
        fclose(file);
        return 1;
    }

    // --- Validate BMP format ---
    // This program specifically supports 24-bit uncompressed BMPs.
    if (info_header.biBitCount != 24) {
        fprintf(stderr, "Unsupported BMP: Only 24-bit BMPs are supported (biBitCount: %u).\n", info_header.biBitCount);
        fclose(file);
        return 1;
    }
    if (info_header.biCompression != 0) {
        fprintf(stderr, "Unsupported BMP: Only uncompressed BMPs are supported (biCompression: %u).\n", info_header.biCompression);
        fclose(file);
        return 1;
    }
     if (info_header.biPlanes != 1) {
        fprintf(stderr, "Unsupported BMP: Number of color planes must be 1 (biPlanes: %u).\n", info_header.biPlanes);
        fclose(file);
        return 1;
    }


    // Get image dimensions
    int width = info_header.biWidth;
    int abs_height = (info_header.biHeight < 0) ? -info_header.biHeight : info_header.biHeight;
    int is_bottom_up = (info_header.biHeight > 0); // True if biHeight is positive

    // --- Allocate memory for the binary matrix ---
    int **binary_matrix = (int **)malloc(abs_height * sizeof(int *));
    if (!binary_matrix) {
        perror("Failed to allocate memory for matrix rows");
        fclose(file);
        return 1;
    }
    for (int i = 0; i < abs_height; ++i) {
        binary_matrix[i] = (int *)malloc(width * sizeof(int));
        if (!binary_matrix[i]) {
            perror("Failed to allocate memory for matrix columns");
            // Free already allocated rows before exiting
            for (int j = 0; j < i; ++j) {
                free(binary_matrix[j]);
            }
            free(binary_matrix);
            fclose(file);
            return 1;
        }
    }

    // Move file pointer to the start of pixel data
    fseek(file, file_header.bfOffBits, SEEK_SET);

    // Calculate row padding
    // Each row in a BMP file is padded to be a multiple of 4 bytes.
    int bytes_per_pixel = info_header.biBitCount / 8; // Should be 3 for 24-bit
    int unpadded_row_size = width * bytes_per_pixel;
    int padding = (4 - (unpadded_row_size % 4)) % 4;
    // if (padding == 4) padding = 0; // This check is redundant with % 4
    int padded_row_size = unpadded_row_size + padding;

    // Allocate buffer to read one row of pixel data
    unsigned char *row_buffer = (unsigned char *)malloc(padded_row_size);
    if (!row_buffer) {
        perror("Failed to allocate memory for row buffer");
        free_matrix(binary_matrix, abs_height);
        fclose(file);
        return 1;
    }

    // --- Read pixel data and convert to binary matrix ---
    // The "black and white conversion" happens here by thresholding luminance.
    for (int y_file = 0; y_file < abs_height; ++y_file) {
        // Read one full row (including padding)
        if (fread(row_buffer, 1, padded_row_size, file) != padded_row_size) {
            fprintf(stderr, "Error reading pixel data for row %d.\n", y_file);
            free(row_buffer);
            free_matrix(binary_matrix, abs_height);
            fclose(file);
            return 1;
        }

        // Determine the target row index in our matrix based on BMP orientation
        int matrix_row_idx = is_bottom_up ? (abs_height - 1 - y_file) : y_file;

        for (int x = 0; x < width; ++x) {
            // Pixels in BMP are typically stored in BGR order
            unsigned char b = row_buffer[x * bytes_per_pixel + 0];
            unsigned char g = row_buffer[x * bytes_per_pixel + 1];
            unsigned char r = row_buffer[x * bytes_per_pixel + 2];

            // Convert to grayscale using a common luminance formula (NTSC standard)
            // L = 0.299*R + 0.587*G + 0.114*B
            float luminance = 0.299f * r + 0.587f * g + 0.114f * b;

            // Apply threshold to determine black (0) or white (1)
            // A common threshold is 128 (midpoint of 0-255 range).
            binary_matrix[matrix_row_idx][x] = (luminance >= 128.0f) ? 1 : 0;
        }
    }

    // Clean up resources
    free(row_buffer);
    fclose(file);

    // --- Print the binary matrix ---
    printf("\nBinary Matrix (0 for black, 1 for white):\n");
    for (int i = 0; i < abs_height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%d ", binary_matrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated matrix memory
    free_matrix(binary_matrix, abs_height);

    printf("\nBMP to binary matrix conversion complete.\n");

    return 0;
}