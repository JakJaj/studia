#include <stdio.h>
#define DLUGOSC 20
int main(void)
{
  unsigned long nrWiersza = 1, ileZnakow = 0;
  int znak;
  while( (znak = getchar()) != EOF ) {
      
      if(znak == '\n') {
        if(ileZnakow > DLUGOSC) printf("%lu\n", nrWiersza);
        
        nrWiersza++;
        ileZnakow = 0;
        }
  ileZnakow++;
}
return 0;
}
