import sys

def load(file):
    """Open a text file & turn contents into a list of lowercase strings."""
    try:
        with open(file) as in_file:
            loaded_txt = in_file.read().lower().strip(" ")
            return loaded_txt
    except IOError as e:
        print("{}\nError opening {}. Terminating program.".format(e, file),
              file=sys.stderr)
        sys.exit(1)

def counter(x,y):
    count = {}
    for i in range(x, y):
        count[chr(i)] = word.count(chr(i))
        Bar = ""
        for j in range (word.count(chr(i))):
            Bar = Bar + "|"
        print(f"{chr(i)}:\t{word.count(chr(i))}:\t{Bar}")
    return count

def biggest(count):
    oldkey = 0
    lsg = "keine Vorhanden"
    for key in count.keys():
        if count[key] > oldkey:
            oldkey = count[key]
            lsg = key
    return lsg

word = load(r"Python\Vorlesung_2\file.txt")

letter_count = {
}
ziffer_count = {
}
zeichen_count = {
}

print("\nZeichen")
zeichen_count = counter(33,47)
zeichen_count.update(counter(58,64))
zeichen_count.update(counter(91,96))
zeichen_count.update(counter(123,126))

print("\nZiffern")
ziffer_count = counter(48,57)

print("\nBuchstaben")
letter_count = counter(97,122)

lsg_Zeichen = biggest(zeichen_count)
lsg_Ziffer = biggest(ziffer_count)
lsg_buchstabe = biggest(letter_count)

print(f"\nHäufigster Buchstabe \t=\t", lsg_buchstabe)
print(f"Häufigste Ziffer \t= \t", lsg_Ziffer)
print(f"Häufigstes Zeichen \t= \t", lsg_Zeichen)