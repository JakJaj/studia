#include <stdio.h>

void split(const char *source, char *autor, char *tytul, char *ilosc, char *cena, char delim){
    while (*source != '\n')
    {
        
    while (*source != delim) { //AUTOR
         *autor = *source;
            autor++;
            source++;
        }
        *autor = '\0';  
        source++;  
    while (*source != delim) { //TYTUL
         *tytul = *source;
            tytul++;
            source++;
        }
        *tytul = '\0';  
        source++;

    while (*source != delim) { //ILOSC
         *ilosc = *source;
            ilosc++;
            source++;
        }
        *ilosc = '\0';  
        source++;
    while (*source != delim) { //CENA
         *cena = *source;
            cena++;
            source++;
        }
        *cena = '\0';  
    }
}

int main(){
    
    char autor[200];
    char tytul [200];
    char ilosc [200];
    char cena[200];
    char src[50] = "jeden;dwa;trzy;cztery\n";
    split(src,autor,tytul,ilosc,cena, ';');
    printf("%s %s %s %s", autor, tytul, ilosc, cena);

    return 0;
}