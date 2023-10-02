from math import floor
from math import ceil

def A(n):
    if n == 1:
        return 1
    return 2 * A ( floor (n / 2)) + 3 * n + 1


def B(n):
    if n == 1:
        return 1
    return 2 * B( ceil (n / 2)) + 3 * n + 1


def C(n):
    if n == 1:
        return 1
    return (C (floor (n / 2)) + C (ceil (n / 2))) + 3 * n + 1

for i in range(1, 33):
    print(f'Dla {i} = Funkcja A: {A(i)} Funkcja B: {B(i)} Funkcja C: {C(i)}')