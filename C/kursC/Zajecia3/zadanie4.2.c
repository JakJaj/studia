#include <stdio.h>
int przesuniecie(int wartosc){
    if(wartosc == 0) return 0;
    int cel = 1;

    while(!(cel & wartosc)){
        wartosc = wartosc >> 1;
    }
    return wartosc;
}
int main(){
    int T,n;
    scanf("%d", &T);
  
    for(int i = 0; i < T; i ++){
        scanf("%d" , &n);
        printf("%d\n", przesuniecie(n));

    }
}