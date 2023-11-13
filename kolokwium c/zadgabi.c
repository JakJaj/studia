#include <stdio.h>

int potega(int a,int b)
{
    if (b==0)
        return 1;
    else
        return a=a*potega(a,--b);
}

int main()
{
    int i, x, r;
    scanf("%d", &x);
    double pomoc = x;
    for(i = 0;  pomoc > 1; i++) //Obliczanie potęgi
        pomoc = pomoc / 10;
    printf("i = %d\n", i);

    long suma = 0;
    while (x != 0)
    {
        r = x % 10;
        suma += potega(r, i);
        x /= 10;
    }

    printf("%d", suma);