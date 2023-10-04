//liczba armstronga (suma cyfr podniesionych do potegi o wykladniku dlugosci liczby)
#include <stdio.h>
int potega(int,int);

int main(){
    int liczba_a, dlugosc ,wykladnik, liczba, x;
    double temp;
    long long suma = 0;

    printf("Podaj liczbe aby sprawdzic czy jest ona liczba Armstronga:\n");
    scanf("%d",&liczba_a);
    temp = liczba_a;
    
      for(wykladnik = 0;  temp > 1; wykladnik++){ 
        //obliczanie do jakiej potegi podnosimy pojedyncze liczby
        temp = temp / 10;
      }

    int liczba_do_sprawdzenia_wyniku = liczba_a;
    while (liczba_a != 0) { 
        //przechodzenie po pojedynczych liczbach potegowanie ich i sumowanie

        x = liczba_a % 10;
        suma += potega(x, wykladnik);
       liczba_a /= 10;

    }
    
    if(suma == liczba_do_sprawdzenia_wyniku)
        printf("TAK");

    else
        printf("NIE");
    
}

//potega z zadania 1
int potega(int liczba,int wykladnik){
    if (wykladnik == 1)
    {
        return liczba;
    }
    int temp = potega(liczba, wykladnik - 1);
    return liczba * temp;
}