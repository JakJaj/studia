with open("C:\\Users\\Jakub\\Desktop\\vscode\\aip\\slowo_ilosc.txt") as plik:
    text = []
    for line in plik:
        text.append(line[:-1])
    text = text[1:]

slownik = {}
slowo = ""
liczba = ""
slowa = []
liczby = []
for i in text:
    for litera in i:
        if litera != ",":
            if litera.isnumeric():
                liczba += litera
            else:
                slowo += litera
    if slowo != "":
        slowa.append(slowo)
    if liczba != "":
        liczby.append(liczba)
        
    slowo = ""
    liczba = ""

for i in range(len(slowa)):
    slownik[slowa[i]] = liczby[i]

print(slownik)