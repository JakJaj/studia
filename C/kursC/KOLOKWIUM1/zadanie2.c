#include <stdio.h>

int zliczanie(char* znak, char zliczanyZnak){
    static int wystapienia = 0;

    if(*znak == zliczanyZnak){
        wystapienia++;
    }
    return wystapienia;
}
int main()
{
   size_t len = 0;
   char *line = NULL;
   int wystapienia;
   getline(&line,&len,stdin);
   int i = 0;
   while (line[i] != '\0')
   {
    wystapienia = zliczanie(&line[i], line[1]);
    i++;
   }
   printf("Tekst ma %d znakow %c.\n",wystapienia, line[1]);
 
   return 0;
}

