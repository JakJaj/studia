import math
import time
def sortowanieKoktailowe(L):
    '''Funkjca sortuje rosnąco tablicę podaną jako jedyny argument funkcji'''
    lewo = 0
    prawo = len(L)-1
    zamiana = 1
    while (zamiana!=0):
        zamiana = 0

        #Z lewej do prawej
        for i in range (lewo, prawo):
            if (L[i] > L[i+1]) :
                pom = L[i]
                L[i] = L[i+1]
                L[i+1] = pom
                zamiana = 1
                
        if (zamiana==0):
            break
        zamiana = 0
        prawo = prawo-1
        
        #Z prawej do lewej
        for i in range(prawo-1, lewo-1,-1):
            if (L[i] > L[i+1]):
                pom = L[i]
                L[i] = L[i+1]
                L[i+1] = pom
                zamiana = 1

        lewo = lewo+1
    return L

pisquared = math.pi**2
euler = math.e
tab = [25, 9, euler, 0.17, 88, 7, 0, 10, -97, pisquared]

print("Tablica przed posortowaniem:")
print(tab)

start = time.time()
posortowana = sortowanieKoktailowe(tab)
end = time.time()
czas = end - start

print("Po posortowaniu:")
print(posortowana)
print("Czas wykonywania algorytmu:")
print(f'{czas} sekund')