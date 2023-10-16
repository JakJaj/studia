#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ 
  printf("Ilosc parametrow podanych przez uzytkownika to %d\n", argc);
  int i;
  for(i = 0; i<argc; i++){
      printf("parametr numer %d to %s\n", i, argv[i]);
  }
  double liczba = atof(argv[1]);
  printf("%4.2f", liczba);
  return 0;
}
