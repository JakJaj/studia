#include <stdio.h>
#define PI 3.141592

// Funkcja oblicza pole koła o podanym promieniu
double pole_kola(double r)
{
    return PI*r*r;
}

int main()
{
    double r;
    printf("Podaj promień kola: ");
    scanf("%lf",&r);
    double p = pole_kola(r);
    printf("Pole tego kola to: %6.4f\n", p);
    return 0;
}
