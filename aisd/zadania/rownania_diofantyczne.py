def NWD_rozszerzony(a,b):
    if b == 0:
        return (a,1,0)
    else:
        d, x, y = NWD_rozszerzony(b,a%b)
        return (d, y, x - (a//b * y))

def rownanie_diofantyczne(a, b, c):
    gcd, x, y = NWD_rozszerzony(a, b)
    if c % gcd != 0:
        return None
    else:
        x *= c // gcd
        y *= c // gcd
        return (x, y)

a = 3
b = 5
c = 7
rozwiazanie = rownanie_diofantyczne(a, b, c)
if rozwiazanie:
    print("Rozwiązanie to x =", rozwiazanie[0], "y =", rozwiazanie[1])
else:
    print("Równanie nie ma rozwiązania")