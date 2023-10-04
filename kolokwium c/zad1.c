//potegowanie rekurencyjnie 
#include <stdio.h>

int potega(int, int);

int main(){
    int liczba, wykladnik;
    printf("Podaj liczbe ktora chcesz podniesz do potegi: \n");
    scanf("%d", &liczba);

    printf("Podaj liczbe ktore chcesz zastosowac jako wykladnik: \n");
    scanf("%d", &wykladnik);
    
    printf("%d\n",potega(liczba, wykladnik));

    return 0;
}

int potega(int liczba,int wykladnik){
    if (wykladnik == 1)
    {
        return liczba;
    }
    int temp = potega(liczba, wykladnik - 1);
    return liczba * temp;
}