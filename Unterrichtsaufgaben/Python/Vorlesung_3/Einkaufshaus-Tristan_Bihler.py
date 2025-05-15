print("Wilkommen im Supermarkt")
print("Welches Produkt möchten Sie kaufen")

def load(file):
    """Open a text file & turn contents into a list of lowercase strings."""
    try:
        with open(file) as in_file:
            loaded_txt = in_file.read().lower().strip(" ").split("\n")
            return loaded_txt
    except IOError as e:
        print("{}\nError opening {}. Terminating program.".format(e, file),
              file=sys.stderr)
        sys.exit(1)

Datei = load(r"Python\Vorlesung_3\Produktliste.txt")
Produkt_liste = {
}
momentarer_Warenkorb={
}
def Warenkorb(Produkt_liste, momentarer_Warenkorb,Produkt, menge):
    try:
        momentarer_Warenkorb[list(Produkt_liste)[Produkt]] = (momentarer_Warenkorb[list(Produkt_liste)[Produkt]][0] + menge, momentarer_Warenkorb[list(Produkt_liste)[Produkt]][1] + Produkt_liste[list(Produkt_liste)[Produkt]][0] * menge, momentarer_Warenkorb[list(Produkt_liste)[Produkt]][2] + Produkt_liste[list(Produkt_liste)[Produkt]][1] * menge)
    except:
        momentarer_Warenkorb[list(Produkt_liste)[Produkt]] = (menge, Produkt_liste[list(Produkt_liste)[Produkt]][0] * menge, Produkt_liste[list(Produkt_liste)[Produkt]][1] * menge)
    for key in momentarer_Warenkorb:
        print(f"Sie haben {momentarer_Warenkorb[key][0]} {key}, im Wert von {momentarer_Warenkorb[key][1]} Euro, mit einem Gewicht von {momentarer_Warenkorb[key][2]} kg, in ihrem Warenkorb")
    return momentarer_Warenkorb

index = 0
for P in Datei:
    index = index + 1
    P = P.split(":")
    print(index, P)
    Produkt_liste[P[0]] = (int(P[1]) , int(P[2]))

print(Produkt_liste)

Produkt = 0
while Produkt != 100:
    try:
        Produkt = int(input("Was möchten Sie kaufen? Mit der eingabe 99 können Sie den Laden verlassen\n")) + 1
        menge = int(input(f"Wie viel möchten sie von {list(Produkt_liste)[Produkt]}\n"))
        momentarer_Warenkorb = Warenkorb(Produkt_liste, momentarer_Warenkorb, Produkt, menge)
    except:
        pass
