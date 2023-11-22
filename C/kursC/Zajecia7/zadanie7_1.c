#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Uzupelnij brakujacy kod:

typedef struct{
    int licznik;
    int mianownik;
} wymierna;

int gcd(int a, int b){

    int wynik = ((a < b) ? a : b);
    while (wynik > 0)
    {
        if(a % wynik == 0 && b % wynik == 0){
            break;
        }
        wynik--;
    }
    return wynik;
}

wymierna suma(wymierna A, wymierna B){
    wymierna wynik;
    int mianownik = A.mianownik * B.mianownik;
    int licznik = A.licznik * B.mianownik + B.licznik * A.mianownik;
    int nwd = gcd(mianownik,licznik);
    wynik.licznik = licznik / nwd;
    wynik.mianownik = mianownik / nwd;
    return wynik;
}

void wypiszWymierna(wymierna ulamek){
    printf("%d/%d\n", ulamek.licznik, ulamek.mianownik);
}
int main(){
  wymierna pierwsza, druga, wynik;
  int T;

  scanf("%d", &T);
  for(int i =0; i < T; i++){
    scanf("%d %d %d %d", &pierwsza.licznik, &pierwsza.mianownik, &druga.licznik, &druga.mianownik);
    wynik = suma(pierwsza, druga);
    printf("Suma ulamkow: ");
    wypiszWymierna(wynik);
  }
  return 0;
}