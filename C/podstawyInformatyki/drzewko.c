#include <stdio.h>
void rysuj_trojkaty(int n,int przesuniecie);
void rysuj_pieniek(int n, int przesuniecie);


int main(){

  int n;
  int ilosc = 3;
  
  printf("Podaj dlugosc boku trójkąta: ");
  scanf("%d",&n);
  int przesuniecie = 2;

  for(int i = 1;i<=ilosc;i++){
    rysuj_trojkaty(n + i * 2, przesuniecie);
    przesuniecie = przesuniecie - 1;
 } 
  przesuniecie = 6 ;

  rysuj_pieniek(n, przesuniecie);
  return 0;
}

void rysuj_trojkaty(int n, int przesuniecie){
  if (przesuniecie == 2)
  {
    for (int x = n/2 + 1; x <= n; x++)
      {
        for (int j = 1; j <= przesuniecie;j ++)
        {
        printf(" ");
        }
          for (int y = 1 ; y  <= n ; y++)
          {
            
              if (x == n  || x == y || y == (n-x+1)) 
                printf("*");           
              else
                  printf(" ");           
          }
          printf("\n");
      }
  }
  else
  {
    for (int x = n/2 + 6; x <= n; x++)
      {
        for (int j = 1; j <= przesuniecie;j ++)
        {
        printf(" ");
        }
          for (int y = 1 ; y  <= n ; y++)
          {
            
              if (x == n  || x == y || y == (n-x+1)) 
                printf("*");           
              else
                  printf(" ");           
          }
          printf("\n");

  }
  }
}

void rysuj_pieniek(int n, int przesuniecie){

  for (int x = 1; x <= n/ 3; x++)
  {
    for (int j = 1; j <= przesuniecie; j++){
      printf(" ");
    }
    for (int y = 1 ; y  <=  n - 6; y++)
    {
      if (x == n/3|| y == n - 6  || y == 1 )
      //                  prawa kreska   lewa kreska
        printf("#");
      
      else
        printf(" ");
      
    }
    printf("\n");
  }
}