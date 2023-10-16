#include <stdio.h>
#include "MojaFunkcja.h"



int main(){
  double r = 5.18;
  printf("Pole koła o promieniu  %4.2f wynosi %5.2f\n", r, CircleA(r));

  return 0;
}
//kompilacja: gcc -std=gnu99 prz2.c -lm
