#include <stdio.h>

unsigned tablica[ROZMIAR][ROZMIAR];

void wypelnij() {
    int liczba = 1;
    int left = 0, right = ROZMIAR - 1, top = 0, bottom = ROZMIAR - 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            tablica[top][i] = liczba++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            tablica[i][right] = liczba++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                tablica[bottom][i] = liczba++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                tablica[i][left] = liczba++;
            }
            left++;
        }
    }
}

void wyswietl() {
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            printf("%u", tablica[i][j]);
            if (j < ROZMIAR - 1) {
                printf("\t");
            }
        }
        printf("\n");
    }
}

int main(void) {
    wypelnij();
    wyswietl();
    return 0;
}
