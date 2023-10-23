#include <stdio.h>
#include <ctype.h>
unsigned litery['Z' - 'A' + 1];
unsigned najwiecej = 0;

void czytaj(void){
  int c;
  while( (c = getchar()) != '\n' ){
    if( isalpha(c)){
      int znak = toupper(c);
      litery[znak - 'A']++;
      if(litery[znak - 'A'] > najwiecej)
         najwiecej = litery[znak-'A'];
    }
    
  }
}



void rysuj(void){
/*
Funkcja wyświetla histogram na podstawie tablicy litery.
Histogram jest skalowany tak, aby jego najdłuższy wiersz
miał MAKS_DL znaków.
*/
  
  for(int litera = 0; litera < 26; litera++){
    int skala = (litery[litera] * MAKS_DL) / najwiecej;
    putchar('A' + litera);
    putchar(':');
    putchar('\t');

    for(int hashtag = 0; hashtag < skala; hashtag++){
      putchar('#');
    }
    putchar('\n');
    

  }
}

int main(void){
  czytaj();
  // sprawdzamy, czy został wczytany jakikolwiek znak,
  // aby uniknąć dzielenia przez zero.
  if( najwiecej != 0 ){
  rysuj();
  }
  return 0;
}
