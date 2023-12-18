#include <stdio.h>
#include <stdio.h>

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Wczytaj liczbę linii

    // Pętla wczytująca każdą linię oddzielnie
    for (int i = 0; i < n; i++) {
        int liczba;
        printf("Linia %d: ", i + 1);

        // Wczytaj liczby do momentu końca linii
        while (scanf("%d", &liczba) == 1) {
            printf("%d ", liczba);
            char znak = getchar();
            if (znak == '\n' || znak == EOF) {
                break;
            }
        }

        printf("\n");
    }

    return 0;
}
