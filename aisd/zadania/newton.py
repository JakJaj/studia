B = [1,-5,3,2]
X = [0,1,2]
c = -2

def horner_newton(B,X,c):
    '''
    Funkcja oblicza wartosc wielomianu zapisanego w postaci Newtona    
    '''
    wynik = B[0]
    poprzedni = 1

    for i in range(len(B) - 1):
        poprzedni = B[i + 1] * (c - X[i]) * poprzedni
        wynik += poprzedni
        poprzedni /= B[i + 1]
    
    return wynik

print(horner_newton(B,X,c))
