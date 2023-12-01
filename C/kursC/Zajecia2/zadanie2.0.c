#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  
  int x, y, z;
  int T;
  
  char c;
  
  scanf("%d", &T);

  for (int i = 0; i < T; i++){
      scanf("%d%c%d", &x, &c, &y);

    
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
    
    printf("%d%c%d = %d\n", x, c, y, z);
  }
  return 0;
}
