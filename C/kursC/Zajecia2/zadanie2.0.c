#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  // x,y - argumenty, z - wynik
  int x, y, z;
  int T;
  // c - znak operacji arytmetycznej
  char c;
  
  scanf("%d", &T);

  for (int i = 0; i < T; i++){
      scanf("%d%c%d", &x, &c, &y);

    // wykonujemy właściwą operację, oprocz dzielenia:
      if(c == '+') z = x + y;
      else if (c == '-') z = x - y;
      else if (c == '*') z = x * y;
      
      else if (c == '/'){
        if(y != 0){
          z = x / y;
        }else{
        printf("Bledne dane!\n");
        exit(1);
        }
      }
      else{
        printf("Bledne dane!\n");
        exit(1);
      }
      
       
      
      

    // w przypadku dzielenia trzeba sprawdzić czy
    // argument y jest niezerowy:
      

    // nieznana operacja lub dzielenie przez zero:
      
    // wypisujemy wynik
    printf("%d%c%d = %d\n", x, c, y, z);
  }
  return 0;
}
