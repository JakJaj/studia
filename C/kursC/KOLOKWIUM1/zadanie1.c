#include <stdio.h>


void funkcja(int rozmiar, int* adres){
    int liczba;
    int licznik = 0;

    int *ostatni = &adres[rozmiar - 1];
    while(licznik != rozmiar) {
        scanf("%d", &liczba);  
        licznik++;
        *ostatni = liczba;
        ostatni--;
    }
}
    
int main(){
    int T;
    int rozmiar;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &rozmiar);
        int tablica[rozmiar];
        funkcja(rozmiar, tablica);
        printf("Tablica: ");
        for(int i = 0; i < sizeof(tablica) / 4; i++){

        printf("%d\t", tablica[i]);
        }
        printf("\n");
    }
    return 0;
}

