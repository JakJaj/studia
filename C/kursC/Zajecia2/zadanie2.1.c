#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int T;
  int liczba, najmniejsza, najwieksza;
  

  scanf("%d", &T);
  for(int i = 0; i<T; i++){
    // wczytujemy pierwszą liczbę
    scanf("%d", &liczba);
    
    // sprawdzamy czy pierwsza liczba nie jest już ujemna
    if( liczba < 0 ) {
       printf("Pusty ciag danych\n");
       exit(1);
    }
    
    // pierwsza liczba jest największa i najmniejsza
    najmniejsza = liczba;
    najwieksza = liczba;
    
    // wczytujemy kolejne liczby
    while(liczba >= 0) {
    //uzupelnij kod
      if(liczba < najmniejsza) najmniejsza = liczba;
      else if (liczba > najwieksza) najwieksza = liczba;

      // wczytujmy kolejną liczbę
      scanf("%d", &liczba);
    }
    
    // wypisujemy wynik
    printf("Najwieksza wczytana liczba to %d\n", najwieksza);
    printf("Najmniejsza wczytana liczba to %d\n",najmniejsza);
  }
return 0;
}
