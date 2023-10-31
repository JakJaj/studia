#include <stdio.h>
//tu wpisz funkcje

void my_split(const char *source, char *first, char *second, const char delim){

    const char *start = source;

    while (*source != '\0' && *source != delim) {
        source++;
    }

    if (*source == delim) {  
        while (start != source) {
            *first = *start;
            first++;
            start++;
        }
        *first = '\0';  

        source++;  

        
        while (*source != '\0') {
            *second = *source;
            second++;
            source++;
        }
        *second = '\0';  
    } else {
        *first = '\0'; 
        *second = '\0';
    }
}


int main(void){
  int max_n = 200;
  char zrodlo[max_n];
  char strA[max_n];
  char strB[max_n];
  int T;
  scanf("%d%*c", &T);
  for(int i  = 0; i < T; i++){
    fgets (zrodlo, max_n, stdin);
    my_split(zrodlo, strA, strB, ';');
    printf("Pierwszy: %s\n", strA);
    printf("Drugi: %s\n", strB);
  }
  
}
