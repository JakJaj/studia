#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define ZA_MALO_PAMIECI 0

typedef struct wezel {
  
  char *tytul;
  char *autor;
  double cena;
  int ilosc;
  struct wezel *nastepny;
} ksiazka;

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *buttonNowy;
GtkWidget *buttonUsun;
GtkWidget *buttonEdycja;
GtkWidget *buttonPromocja;
GtkWidget *buttonSprzedaz;
GtkWidget *buttonDostawa;
GtkWidget *view1;
GtkWidget *search;
GtkBuilder *builder;
GtkTreeStore *treeStore;
GtkTreeView *tv1;
GtkTreeViewColumn *cx3;
GtkTreeViewColumn *cx2;
GtkTreeSelection *selection;
GtkCellRenderer *cr3;
GtkCellRenderer *cr2;


void push_back(ksiazka *nowy, ksiazka **pierwszy) {

  ksiazka* element;
  ksiazka* iterator = *pierwszy;
  
  if( (element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }

    element->tytul = nowy->tytul;
    element->autor = nowy->autor;
    element->cena = nowy->cena;
    element->ilosc = nowy->ilosc;
    element->nastepny = NULL;
    
    if (iterator == NULL){//gdy pusta lista
        *pierwszy = element;
        return;
    }

    while (iterator->nastepny != NULL){
        iterator = iterator->nastepny;
    }

    iterator->nastepny = element;

}
void split(const char *source, char *autor, char *tytul, char *ilosc, char *cena, char delim){
    *autor = '\0';
    *tytul = '\0';
    *ilosc = '\0';
    *cena = '\0';

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
    while (*source != '\0') { //CENA
         *cena = *source;
            cena++;
            source++;
        }
        *cena = '\0';  

}
bool wypelnijMagazyn(const char *nazwaPliku, ksiazka **pierwszy){
    
    FILE *fp = fopen (nazwaPliku, "r");
    if (fp == NULL) {
       printf("Brak pliku z danymi\n");
       return 0;
    }
    const int max_n= 500;
    char linia[max_n], *result;
    char tytul[200];
    char autor[100];
    char ilosc[10];
    char cena[20];
   
    while(!feof(fp)){
    
       ksiazka *element;
       if ((element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
          fprintf(stderr, "Za mało pamięci!\n");
          exit(ZA_MALO_PAMIECI);
       }
       result = fgets (linia, max_n, fp);
       split(linia, tytul, autor, ilosc, cena, ';');
       
       element->tytul = (char*) malloc((strlen(tytul) + 1) * sizeof(char));
       strcpy(element->tytul, tytul);
       
       element->autor = (char*) malloc((strlen(autor) + 1) * sizeof(char));
       strcpy(element->autor, autor);
       
       element->ilosc = atoi(ilosc);
       element->cena = atof(cena);
       push_back(element, pierwszy);
       
       }
       
    fclose(fp);
    
    return 1;
}


void populate(ksiazka **magazyn, GtkTreeStore *treeStore) {
  ksiazka *iterator = *magazyn;
  GtkTreeIter iter;
  
  
  while (iterator != NULL) {
    g_print("Setting data: Tytul=%s, Autor=%s\n", iterator->tytul, iterator->autor);
    gtk_tree_store_append(treeStore, &iter, NULL);

    gtk_tree_store_set(treeStore, &iter, 0, iterator->tytul, -1);
    gtk_tree_store_set(treeStore, &iter, 1, iterator->autor, -1);
  
    iterator = iterator->nastepny;
  }
  
  gtk_widget_show_all(window);
}


int main (int argc, char *argv[]){
  ksiazka *magazyn = NULL;
    
    char NazwaPliku[15] = "ksiazki.txt";
    bool sukces = wypelnijMagazyn(NazwaPliku, &magazyn);

  gtk_init(&argc, &argv);

  builder = gtk_builder_new_from_file("part1.glade");
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(builder, NULL);

  fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
  view1 = GTK_WIDGET(gtk_builder_get_object(builder, "view1"));
  treeStore = GTK_TREE_STORE(gtk_builder_get_object(builder,"treeStore"));
  tv1 = GTK_TREE_VIEW(gtk_builder_get_object(builder,"tv1"));
  cx3 = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cx3"));
  cx2 = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cx2"));
  cr3 = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cr3"));
  cr2 = GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cr2"));
  selection = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"selection"));
  buttonNowy = GTK_WIDGET(gtk_builder_get_object(builder, "buttonNowy"));
  buttonUsun = GTK_WIDGET(gtk_builder_get_object(builder, "buttonUsun"));
  buttonEdycja = GTK_WIDGET(gtk_builder_get_object(builder, "buttonEdycja"));
  buttonPromocja = GTK_WIDGET(gtk_builder_get_object(builder, "buttonPromocja"));
  buttonSprzedaz = GTK_WIDGET(gtk_builder_get_object(builder, "buttonSprzedaz"));
  buttonDostawa = GTK_WIDGET(gtk_builder_get_object(builder, "buttonDostawa"));
  search = GTK_WIDGET(gtk_builder_get_object(builder, "search"));

  gtk_window_set_title(GTK_WINDOW(window), "Ksiegarnia - Projekt");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  gtk_tree_view_column_add_attribute(cx3,cr3,"text",0);
  gtk_tree_view_column_add_attribute(cx2,cr2,"text",1);


  populate(&magazyn, treeStore);

  gtk_tree_view_set_model(GTK_TREE_VIEW(tv1), GTK_TREE_MODEL(treeStore));

  gtk_widget_show_all(window);

  gtk_main();

  return EXIT_SUCCESS;
}

void on_search_search_changed(GtkSearchEntry *s){
  const gchar *srch;

  srch = gtk_entry_get_text(GTK_ENTRY(s));
  if (strlen(srch) == 0) return;

  printf("Search for: %s\n",srch);
  
}

void on_select_changed(GtkWidget *c){
  gchar *value;
  GtkTreeIter iter;
  GtkTreeModel *model;

  if (gtk_tree_selection_get_selected (GTK_TREE_SELECTION(c), &model, &iter) == FALSE){
    return;
  }
  gtk_tree_model_get(model,&iter,0,&value, -1);
  g_print("col = 0 = %s\n", value);
  gtk_tree_model_get(model,&iter,1,&value, -1);
  g_print("col = 1 = %s\n", value);
}

void on_destroy();