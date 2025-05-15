def bubble_sort(name):
    name = list(name)
    for i in range(len(name)):                                                  # alle Buchstaben durchgehen
        for buchstabe_position in range(len(name)):                             # momentarer Buchstabe
            if (buchstabe_position < len(name) - 1):                            # Gucken das es nicht am ende ist, da sonst durch die +1 die Untersuchung der liste auserhalb liegt
                if name[buchstabe_position] <= name[buchstabe_position+1]:      # Gucken ob der buchstabe kleiner als die nächste position ist
                    pass    
                else:                                                           # Buchstaben tauschen
                    charakter = name[buchstabe_position]
                    name[buchstabe_position] = name[buchstabe_position + 1]
                    name[buchstabe_position + 1] = charakter
    return name


def count_all_letters():
    count = {
        
    }