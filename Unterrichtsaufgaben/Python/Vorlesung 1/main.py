import sys

meine_liste = ['Banane', 'Ananas', 'Axel']
laenge_wort = 0
for wort in meine_liste:
    if (len(wort) > laenge_wort):
        laenge_wort = len(wort)
        Lösung = wort

print(f"Das Wort {Lösung} enthält {laenge_wort} Zeichen")