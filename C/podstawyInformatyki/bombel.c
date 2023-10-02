#include<stdio.h>

void bombel(int lista[], int size);

int main (){
    int size;
    
    printf("Podaj ile liczb chcesz dodac do listy:\n");
    scanf("%d",&size);

    int lista[size];

    for (int i = 0;i < size ;i ++){
        int temp;
        printf("Podaj liczbe nr. %d:\n", i+1);
        scanf("%d",&temp);
        lista[i] = temp;
    }

    printf("Przed:\n");

    for (int i = 0; i < size; i ++){
        printf("%d\n",lista[i]);
    }

    bombel(lista, size);

    printf("\n");
    printf("Po:\n");
    for (int i = 0; i < size; i ++){
        printf("%d\n",lista[i]);
    }
        return 0;
}

void bombel(int lista[],int size){
    int i,j,temp;
    for (i = 0; i <size -1; i ++)
    {
    for (j = 0; j<size - 1; j ++)
    {
        if (lista[j] > lista[j + 1])
        {
            temp = lista[j + 1];
            lista[j + 1] = lista[j];
            lista[j] = temp;
        }
    }
    } 
}