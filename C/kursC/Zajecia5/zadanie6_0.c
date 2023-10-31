#include<stdio.h>
void zamien(double* x, double* y){
    double temp = *x;
    *x = *y;
    *y = temp;
    
}

int main(){

    int T;
    scanf("%d", &T);
    double pierwsza, druga;
    for(int i = 0; i < T;i++){
        scanf("%lf %lf",&pierwsza,&druga);
        printf("wartosc pierwszej liczby = %.4f\n", pierwsza);
        printf("wartosc drugiej liczby = %.4f\n", druga);
        zamien(&pierwsza, &druga);
        printf("Po zamianie:\n");
        printf("wartosc pierwszej liczby = %.4f\n", pierwsza);
        printf("wartosc drugiej liczby = %.4f\n", druga);
    }
    return 0;
}