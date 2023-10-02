#include <stdio.h>

int main(){
    int T;
    int n;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &n);
        printf("%d\t%d\t%d\n", n, n * n ,n * n * n);

    }
    return 0;
}