A = [2,3,-5,2,-1]
stopien_wielomianu = len(A) - 1
punkt = 2

def horner(n,A,c):
    '''
    Funkcja przeprowadzajaca schemat Hornera
    Zwraca liste wspolczynnikow w danym punkcie
    '''
    wartosci = [A[n]]
    
    for i in range(n):
        obliczenia = wartosci[i] * c + A[n - 1 - i]
        wartosci.append(obliczenia)

    return wartosci[::-1]

def hornerPochodne(n,A,c):
    ''' 
    Funkcja przeprowadzajaca schemat Hornera na kolejnych pochodnych 
    Zwraca wszystkie pochodne w danym punkie
    '''
    wyniki = [A]

    for i in range(n):
        dzialanie = horner(n,A,c)
        wyniki.append(dzialanie)
        n = len(dzialanie) - 2
        A = wyniki[i+1]
        A = A[1:]
    
    return wyniki

print(hornerPochodne(stopien_wielomianu,A,punkt))
