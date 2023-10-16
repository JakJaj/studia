#include <stdio.h>

//Zmienna statyczna zadeklarowana w bloku funkcji, 
//zgodnie z definicją pamięta swoją wartość pomiędzy wywołaniami funkcji, 
//co nie jest możliwe przy użyciu zwykłych zmiennych.

int fkcja()
{
    int A = 0;
    static int B = 0;

    printf("Zmienna auto: %d\tZmienna static %d\n", A, B);
    A++; B++;
}

int main()
{
    for(int i = 0; i < 10; i++)
        fkcja();
    return 0;
}
