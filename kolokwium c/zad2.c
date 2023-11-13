//liczbe rozbic na potegi binarna i pliczyc ilosc 1 w liczbie bin
#include <stdio.h>
int dec2bin(int);

int main()
{
    int liczba,lp;
    int licznik = 0;

    printf("Wpisz liczbe by sprawdzic ile liczb roznych poteg 2 potrzeba aby zapisać ta liczbe :");
    scanf("%d", &liczba);

    lp = dec2bin_plus_zliczanie(liczba);
    printf("Liczba poteg 2 potrzebnych do zapisania liczby %d to: %d\n",liczba, lp);
    
    return 0;
}

int dec2bin_plus_zliczanie(int liczba){
    //konwertowanie do bin i w trakcie konwertowania zliczanie wystapien 1
    int reszta, binarna = 0, miejsce = 1, ilosc_1 = 0; 
    
    while (liczba > 0)
    {
        reszta = liczba % 2;
        binarna += reszta * miejsce;
        miejsce *= 10;
        liczba /= 2;

        if (reszta == 1)
        {
            ilosc_1++;
        }
    }
    return ilosc_1;
}