#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NOT_ENOUGH_MEMORY 0
int amountOfBooks = 0;

typedef struct node {
  
  char *title;
  char *author;
  double price;
  int amount;
  struct node *next;
  char *description;
} book;

book *currentlySelected;
book *storage = NULL;


void push_back(book *nowy, book **first) {

  book* element;
  book* iterator = *first;
  
  if( (element = (book*)malloc(sizeof(book))) == NULL ) {
    fprintf(stderr, "Not enough memory!\n");
    exit(NOT_ENOUGH_MEMORY);
  }

    element->title = nowy->title;
    element->author = nowy->author;
    element->price = nowy->price;
    element->amount = nowy->amount;
    element->description = nowy->description;
    element->next = NULL;
    
    if (iterator == NULL){ //empty list
        *first = element;
        return;
    }

    while (iterator->next != NULL){
        iterator = iterator->next;
    }

    iterator->next = element;
    amountOfBooks++;
}
void split(const char *source, char *autor, char *tytul, char *amount, char *price, char *description,char delim){
    *autor = '\0';
    *tytul = '\0';
    *amount = '\0';
    *price = '\0';
    *description = '\0';

    while (*source != delim) { //AUTHOR
         *autor = *source;
            autor++;
            source++;
        }
        *autor = '\0';  
        source++;  
    while (*source != delim) { //TITLE
         *tytul = *source;
            tytul++;
            source++;
        }
        *tytul = '\0';  
        source++;

    while (*source != delim) { //AMOUNT
         *amount = *source;
            amount++;
            source++;
        }
        *amount = '\0';  
        source++;
    while (*source != delim) { //PRICE
         *price = *source;
            price++;
            source++;
        }
        *price = '\0';  
        source++;
    while (*source != '\n') { //DESCRIPTION
         *description = *source;
            description++;
            source++;
        }
        *description = '\0';

}
bool wypelnijMagazyn(const char *nazwaPliku, book **first){
    
    FILE *fp = fopen (nazwaPliku, "r");
    if (fp == NULL) {
       printf("Brak pliku z danymi\n");
       return 0;
    }
    const int max_n= 500;
    char linia[max_n], *result;
    char tytul[200];
    char autor[100];
    char amount[10];
    char price[20];
    char description[500];
   
    while(!feof(fp)){
    
       book *element;
       if ((element = (book*)malloc(sizeof(book))) == NULL ) {
          fprintf(stderr, "Za mało pamięci!\n");
          exit(NOT_ENOUGH_MEMORY);
       }
       result = fgets (linia, max_n, fp);
       split(linia, tytul, autor, amount, price, description,';');
       
       element->title = (char*) malloc((strlen(tytul) + 1) * sizeof(char));
       strcpy(element->title, tytul);
       
       element->author = (char*) malloc((strlen(autor) + 1) * sizeof(char));
       strcpy(element->author, autor);
       
       element->amount = atoi(amount);
       element->price = atof(price);

       element->description = (char*) malloc((strlen(description) + 1) * sizeof(char));
       strcpy(element->description, description);

       push_back(element, first);
       
       }
       
    fclose(fp);
    
    return 1;
}

void deleteBook(book **first, book *element){
    book *iterator = *first;
    book *before = NULL;
    while (iterator != NULL){
        if (iterator == element){
            if (before == NULL){
                *first = iterator->next;
            }else{
                before->next = iterator->next;
            }
            free(iterator);
            amountOfBooks--;
            return;
        }
        before = iterator;
        iterator = iterator->next;
    }
}



