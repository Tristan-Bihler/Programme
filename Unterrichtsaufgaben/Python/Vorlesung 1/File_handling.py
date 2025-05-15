import sys

def load(file):
    """Open a text file & turn contents into a list of lowercase strings."""
    try:
        with open(file) as in_file:
            loaded_txt = in_file.read().lower().strip(" ").split('\n')
            return loaded_txt
    except IOError as e:
        print("{}\nError opening {}. Terminating program.".format(e, file),
              file=sys.stderr)
        sys.exit(1)

liste = load(r"Python\Vorlesung 1\file.txt")
print(liste)
"""
for wort in liste:
    if wort[::1] == wort[::-1]:
        print(wort)
"""

vokale = ["a", "e", "i", "o","u"]

for wort in liste:
    for i in vokale:
        if i in wort:
            vokale.remove(i)
            for j in vokale:
                if j in wort:
                    break
                print(wort)
            vokale.insert(0,i)


"""
if "a" in wort and ("e" in wort or "i" in wort or"o" in wort or "u" in wort):
        pass
    elif "e" in wort and ("a" in wort or "i" in wort or"o" in wort or "u" in wort):
        pass
    elif "i" in wort and ("a" in wort or "e" in wort or"o" in wort or "u" in wort):
        pass
    elif "o" in wort and ("a" in wort or "e" in wort or"i" in wort or "u" in wort):
        pass
    elif "u" in wort and ("a" in wort or "e" in wort or"i" in wort or "o" in wort):
        pass
    else:
        print(wort)

"""
