# prosty
def NWD(a,b):
    while a != b:
        if a > b:

            a = a - b
        else:
            b = b - a
    return a

#rozszerzony
def NWD_rozszerzony(a,b):
    if b == 0:
        return (a,1,0)
    else:
        d, x, y = NWD_rozszerzony(b,a%b)
        return (d, y, x - (a//b * y))

a = 12
b = 4
d, x, y = NWD_rozszerzony(a,b)

#rozwiazanie proste
print(f'NWD({a}, {b}) = {NWD(a,b)}')

#rozwiazanie rozszerzone
print(f"NWD_rozszerzony({a}, {b}) = {d} = {a} * {x} + {b} * {y}")