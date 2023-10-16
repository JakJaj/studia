#include <stdio.h>


int oblicz(int x)
{
  return x * (x * (3 * x * x * x * x * x + 1) -9) + 16;
  
}

int main(void)
{
  int T;
  int xmin, xmax;
  scanf("%d", &T);
  
  for(int i = 0; i < T; i ++){
    scanf("%d %d", &xmin, &xmax);
    
    if(xmin > xmax){
        int temp = xmin;
        xmin = xmax;
        xmax = temp;
    }

    while(xmin <= xmax){
        int temp_horner = oblicz(xmin);
        printf("f(%d) = %d\n", xmin, temp_horner);
        xmin++;
    }
  }
  return 0;
}
