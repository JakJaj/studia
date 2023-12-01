#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define ROZMIAR 32
char slowoA[ROZMIAR], slowoB[ROZMIAR];

bool czyAnagramy() {
  int litery['Z' - 'A' + 1];

  // Czyszczenie tablicy
  for (int i = 'A'; i <= 'Z'; i++) {
    litery[i - 'A'] = 0;
  }

  // Zliczanie liter w pierwszym słowie
  for (int i = 0; slowoA[i] != '\0'; i++) {
    if (isalpha(slowoA[i])) {
      litery[toupper(slowoA[i]) - 'A']++;
    }
  }

  // Zliczanie liter w drugim słowie
  for (int i = 0; slowoB[i] != '\0'; i++) {
    if (isalpha(slowoB[i])) {
      litery[toupper(slowoB[i]) - 'A']--;
    }
  }

  // Słowa są anagramami, jeśli różnica wynosi zero
  for (int i = 0; i <= 'Z' - 'A'; i++) {
    if (litery[i] != 0) {
      return false;
    }
  }

  return true;
}


int main(void){
  int T;
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    scanf("%s%s", slowoA, slowoB);
    
    if( czyAnagramy() )
      printf("Tak\n");
    else
      printf("Nie\n");
  }
  return 0;
}