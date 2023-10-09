#include <stdio.h>
int main(void){
  int iloscSeg, nrSegmentu, nrWiersza, nrKolumny;

  // wczytujemy liczbę segmentów
  //printf("Podaj ilość segmentów choinki: ");
  scanf("%d", &iloscSeg);
  
  // pętla po segmentach
  for(nrSegmentu = 1; nrSegmentu < iloscSeg + 1; nrSegmentu++) {
  
     // pętla po wierszach segmentu
     for(nrWiersza = 0; nrWiersza < nrSegmentu + 1; nrWiersza++) {
         
         // pętla po kolumnach "rysunku"
         for(nrKolumny = 0; nrKolumny < iloscSeg + nrWiersza + 1; nrKolumny++) {
            // rysujemy odstęp czy choinkę?
            if( nrKolumny < iloscSeg - nrWiersza )
               putchar(' ');
            else
               putchar('*');
         }
        
        // przechodzimy do nowej linii
        putchar('\n');
     }
  }
  return 0;
}
