# Importieren der Pygame-Bibliothek
import pygame

# initialisieren von pygame
pygame.init()

# genutzte Farbe
ORANGE  = ( 255, 140, 0)
ROT     = ( 255, 0, 0)
GRUEN   = ( 0, 255, 0)
SCHWARZ = ( 0, 0, 0)
WEISS   = ( 255, 255, 255)

cube_position = [50,50]
# Fenster öffnen
screen = pygame.display.set_mode((640, 480))

# Titel für Fensterkopf
pygame.display.set_caption("Unser erstes Pygame-Spiel")

# solange die Variable True ist, soll das Spiel laufen
spielaktiv = True

# Bildschirm Aktualisierungen einstellen
clock = pygame.time.Clock()

# Schleife Hauptprogramm
while spielaktiv:
    # Überprüfen, ob Nutzer eine Aktion durchgeführt hat
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            spielaktiv = False
            print("Spieler hat Quit-Button angeklickt")
        elif event.type == pygame.KEYDOWN:
            print("Spieler hat Taste gedrückt")

            # Taste für Spieler 1
            if event.key == pygame.K_RIGHT:
                print("Spieler hat Pfeiltaste rechts gedrückt")
            elif event.key == pygame.K_LEFT:
                print("Spieler hat Pfeiltaste links gedrückt")
            elif event.key == pygame.K_UP:
                print("Spieler hat Pfeiltaste hoch gedrückt")
            elif event.key == pygame.K_DOWN:
                print("Spieler hat Pfeiltaste runter gedrückt")
            elif event.key == pygame.K_SPACE:
                print("Spieler hat Leertaste gedrückt")

            # Taste für Spieler 2
            elif event.key == pygame.K_w:
                print("Spieler hat Taste w gedrückt")
                cube_position[0] = cube_position[0] - 10
            elif event.key == pygame.K_a:
                print("Spieler hat Taste a gedrückt")
                cube_position[1] = cube_position[1] - 10
            elif event.key == pygame.K_s:
                print("Spieler hat Taste s gedrückt")
                cube_position[0] = cube_position[0] + 10
            elif event.key == pygame.K_d:
                print("Spieler hat Taste d gedrückt")
                cube_position[1] = cube_position[1] + 10

        elif event.type == pygame.MOUSEBUTTONDOWN:
            print("Spieler hast Maus angeklickt")

    if cube_position[1] + 100 >= 640:
        cube_position[1] = cube_position[1] - 10
    elif cube_position[1] <= 0:
        cube_position[1] = cube_position[1] + 10
    
    if cube_position[0] + 100 >= 480:
        cube_position[0] = cube_position[0] - 10
    elif cube_position[0] <= 0:
        cube_position[0] = cube_position[0] + 10
    
    # Spiellogik hier integrieren

    # Spielfeld löschen
    screen.fill(WEISS)
    pygame.draw.rect(screen, ROT, [cube_position[1], cube_position[0], 100, 100], 1)
    pygame.draw.rect(screen, ROT, [300, 300, 50, 50], 1)


    # Spielfeld/figuren zeichnen

    # Fenster aktualisieren
    pygame.display.flip()

    # Refresh-Zeiten festlegen
    clock.tick(60)

pygame.quit()