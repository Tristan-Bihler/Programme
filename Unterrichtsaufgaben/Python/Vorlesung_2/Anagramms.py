"""Find all the anagrams in a dictionary file for a given word.

Requires access to an external English word dictionary file
and file-loading module "load_dictionary.py"

"""

import load_dictionary
import helperfunktion as hf
word_list = load_dictionary.load(r'Python\Vorlesung_2\2of4brif.txt')

anagram_list = []

# input a SINGLE word or SINGLE name below to find its anagram(s):
input_word = input("Input a word that you want an anagramm of\n").lower()

name = {
    "name": input_word,
    "length": len(input_word),
    "sorted": hf.bubble_sort(input_word)
}

""""
name = 'Foster'
print("Input name = {}".format(name))
name = name.lower()
print("Using name = {}".format(name))


# sort name and find anagrams
name_sorted = sorted(name)
print(name_sorted)

name_sorted = (hf.bubble_sort(name))
print(name_sorted)
"""

for word in word_list:
    if name["length"] == len(word):
        word = word.lower()
        if word != name["name"]:
            if sorted(word) == list(name["sorted"]):        
                anagram_list.append(word)

#print out list of anagrams
print()
if len(anagram_list) == 0:
    print("You need a larger dictionary or a new name!")
else:
    print("Anagrams =", *anagram_list, sep='\n')