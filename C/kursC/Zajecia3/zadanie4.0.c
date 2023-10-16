#include <stdio.h>

int nwd(int p, int q){

    while(p != q){
        if(p > q){
            p -= q;
        }
        else{
            q -= p;
        }
    }
    return p;
}

int main(void)
{ 
  int T = 0;
  scanf("%d", &T);
  int x,y,n;
  for(int i = 0; i < T ; i++){

    scanf("%d%d", &x, &y);

    n = nwd(x, y);
    printf("nwd(%d, %d) = %d\n", x, y, n);
   
    int nww = (x * y) / nwd(x,y);
    printf("nww(%d, %d) = %d\n", x, y, nww);
  }
  return 0;
}
