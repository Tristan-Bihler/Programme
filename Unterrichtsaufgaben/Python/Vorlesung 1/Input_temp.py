import sys
print("If you want to close the programm, then write break")
with open(r"Python\Vorlesung 1\demofile.txt", "w") as f:
  while 1:
    temp = input("Geben sie eine Temperatur ein \n")
    if (temp == "break"):
      break
    fahrenheit = (int(temp)*1.8) + 32
    f.write(f"Grad-Celsius = {temp} \t Fahrenheit = {fahrenheit}\n")