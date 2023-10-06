from random import randint
import matplotlib.pyplot as plt
import numpy as np
EX = 0
wartosci = []
kolejne_wartosci = []
n = 100
k = 50
for i in range(1,k):
    for j in range(n):
        ran = randint(1,6)
        wartosci.append(ran)

    EX = sum(wartosci) / (n * i)
    kolejne_wartosci.append(EX)


x = [i for i in range(k - 1)]
y = kolejne_wartosci

# rysowanie wykresu
plt.plot(x, y)
plt.xlabel('Liczba rzutów')
plt.ylabel('EX')
plt.yticks([i/2 for i in range(0, 21)])

# dodanie tytułu wykresu
plt.title('Wykres wartosci oczekiwanej dla rzutu kością')
plt.ylim(1,6)
# wyświetlenie wykresu
plt.show()