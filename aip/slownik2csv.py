def  czysc(napis):
    """
    Funkcja czyści dany tekst z ...
    """
    wynik = ""
    import string 
    znaki = string.ascii_letters+" "+"'"
    
    
    for el in napis:
        if el in znaki:
            wynik += el
    return wynik


def add2dict(napis):
    """
    """
    s = {}
    lista = napis.split(" ")
    for el in lista:
        if el in s:
            s[el] += 1
        else:
            s[el] = 1
    return s

with open('C:\\Users\\Jakub\\Desktop\\vscode\\aip\\text.txt') as plik:
    napis = plik.read().lower()
napis = napis.replace("\n"," ")
napis = add2dict(czysc(napis))

print(napis)

with open("C:\\Users\\Jakub\\Desktop\\vscode\\aip\\slowo_ilosc.txt",mode="w") as plik:
    plik.write("#slowo,ilosc\n")
    for key, val in sorted(napis.items(), key=lambda x : x[1],reverse=True):
        plik.writelines(f"{key},{val}\n")

