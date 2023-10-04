//liczby skojarzone (liczba a jest skojarzone z b jesli a + 1 = b )
#include <stdio.h>

int suma_dzielniki(int);

int main(){
    int liczba_a, i = 0, sumaA, liczba_b;

    printf("Podaj liczbe a: \n");
    scanf("%d",&liczba_a);
    
    
    if (liczba_a > 1)
    {
        sumaA = suma_dzielniki(liczba_a);
        liczba_b = sumaA - 1;
        
    }
    if (liczba_b != 0)
        printf("Liczba skojarzona z liczba %d jest liczba %d", liczba_a, liczba_b);
    else
        printf("NIE", liczba_a);
    
    return 0;
}

int suma_dzielniki(int liczba){
    int suma = 0;
    for (int i = 1;i < liczba; i++){
        if (liczba % i == 0){
            suma = suma + i;
        }
    }
    return suma;
}