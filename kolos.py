from random import randint
ludzie = ['gabi','marcin','wojtek','jakub','bartosz']
gr1 = []
gr2 = []
gr3 = []
licznik = 0

while len(gr1) + len(gr2) + len(gr3) < 5:
    losowanie = randint(1,3)
    
    if len(gr1) < 2 and losowanie == 1:
        gr1.append(ludzie.pop())

    elif len(gr2) < 2 and losowanie == 2:
        gr2.append(ludzie.pop())

    elif len(gr3) < 2 and losowanie == 3:
        gr3.append(ludzie.pop())
    
print('Grupa 1')
print(gr1)
print('Grupa 2')
print(gr2)
print('Grupa 3')
print(gr3)