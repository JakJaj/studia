import math

def sito_eratostenesa(n):
    liczby = [True] * (liczba + 1)

    for i in range(2,int(math.ceil(math.sqrt(liczba)))):
        if liczby[i]:
            for k in range(i**2,liczba+1,i):
                liczby[k] = False
    return liczby

liczba = int(input("Podaj do której liczby wyznaczyć liczby pierwsze: "))
pierwsze = sito_eratostenesa(liczba)

print(f'Liczby pierwsze do liczby {liczba}: ')
for i in range(2,liczba + 1):
        if pierwsze[i]:
            print(i, end=' ')