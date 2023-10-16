#include<stdio.h>
#include<stdarg.h>

//https://en.wikipedia.org/wiki/Stdarg.h

void printargs(int n, ...)
{
  va_list lista_argumentow;//uchwyt listy
  int i;

  va_start(lista_argumentow, n); 
  for (i = 0; i < n; i++){
    //kolejne wywolania makropolecenie va_arg zwracają
    //kolejne argumenty funkcji.
    //Makropolecenie przyjmuje 2 argumenty: uchwyt listy
    //oraz typ kolejnego argumentu funkcji.
    int arg = va_arg(lista_argumentow, int);
    printf("%d\t%d\n", i, arg);
  }
  va_end(lista_argumentow);
}

int main(void)
{
   printargs(5, 2, 14, 84, 97, 15, -1, 48, -1);
   printf("nowa lista argumentow:\n");
   printargs(84, 51, -1);
   printf("nowa lista argumentow:\n");
   printargs(-1);
   printf("nowa lista argumentow:\n");
   printargs(1, -1);
   return 0;
}
