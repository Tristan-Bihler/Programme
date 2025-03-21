#include <stdio.h>

// Funktion zum Vertauschen zweier Elemente
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Funktion zum Partitionieren des Arrays
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot-Element ist das letzte Element
    int i = (low - 1); // Index des kleineren Elements

    for (int j = low; j <= high - 1; j++) {
        // Wenn das aktuelle Element kleiner oder gleich dem Pivot ist
        if (arr[j] <= pivot) {
            i++; // Inkrementiere den Index des kleineren Elements
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort-Funktion
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi ist der Partitionierungsindex, arr[p] ist nun an der richtigen Stelle
        int pi = partition(arr, low, high);

        // Sortiere Elemente vor und nach der Partitionierung rekursiv
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hilfsfunktion zum Drucken eines Arrays
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sortiertes Array: \n");
    printArray(arr, n);
    return 0;
}