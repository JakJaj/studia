#include <stdio.h>
int main()
{
  char wybrany, biezacy;
  int trafienia, wszystkie;
  int T;
  scanf("%d%*c", &T);
  
  for(int i  = 0; i < T; i++){

      scanf("%c\n", &wybrany);
      printf("Zliczany znak to: %c\n", wybrany);

      // inicjujemy zmienne
      trafienia = 0;
      wszystkie = 0;

      // wczytujemy linie tekstu z wejscia
      
      while( (biezacy = getchar()) != '\n' ) {
      //uzupelnij kod
      if(biezacy == wybrany){ 
        trafienia++;
        wszystkie++;
      }
      else wszystkie++;}
      
      int procent = trafienia * 100 / wszystkie;
      // unikamy dzielenia przez zero
      if( wszystkie == 0 )
          printf("Czestotliwosc wystepowania to 0 %%\n");
      else
          printf("Czestotliwosc wystepowania to %d %%\n", procent);
  }
  return 0;
}
