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
#include "struktura.h"
#include "addNewBook.h"
#include "modifyBook.h"
#define ZA_MALO_PAMIECI 0

//main window
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
GtkTextBuffer *textBuffer;
GtkWidget *textView;
int rowNbr;

//delete window
GtkWidget *windowDelete;
GtkWidget *fixed3;
GtkWidget *buttonDeleteNo;
GtkWidget *buttonDeleteYes;
GtkWidget *labelDeleteAuthor;
GtkWidget *labelDeleteTitle;
GtkBuilder *builderDelete;

//discount window
GtkWidget *windowDiscount;
GtkWidget *fixed5;
GtkWidget *buttonDiscountCancel;
GtkWidget *buttonDiscountConfirm;
GtkWidget *labelDiscountAuthor;
GtkWidget *labelDiscountTitle;
GtkWidget *labelDiscountPrice;
GtkWidget *entryDiscountPercent;
GtkWidget *viewDiscountPercent;
GtkBuilder *builderDiscount;

//sell window
GtkWidget *windowSell;
GtkWidget *fixed6;
GtkWidget *buttonSellCancel;
GtkWidget *buttonSellConfirm;
GtkWidget *labelSellAuthor;
GtkWidget *labelSellTitle;
GtkWidget *labelSellAmount;
GtkWidget *entrySellAmount;
GtkWidget *viewSellAmount;
GtkBuilder *builderSell;

//delivery window
GtkWidget *windowDelivery;
GtkWidget *fixed7;
GtkWidget *buttonDeliveryCancel;
GtkWidget *buttonDeliveryConfirm;
GtkWidget *labelDeliveryAuthor;
GtkWidget *labelDeliveryTitle;
GtkWidget *labelDeliveryAmount;
GtkWidget *entryDeliveryAmount;
GtkWidget *viewDeliveryAmount;
GtkBuilder *builderDelivery;

void populate(ksiazka **magazyn, GtkTreeStore *treeStore) {
  ksiazka *iterator = *magazyn;
  currentlySelected = *magazyn;

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

void on_destroy(){
  //save items to file!
  gtk_main_quit();
}

int main (int argc, char *argv[]){
  
    char NazwaPliku[15] = "ksiazki.txt";
    bool sukces = wypelnijMagazyn(NazwaPliku, &magazyn);

  gtk_init(&argc, &argv);

  builder = gtk_builder_new_from_file("part1.glade");
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
 
  g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

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
  textView = GTK_WIDGET(gtk_builder_get_object(builder, "textView"));

  gtk_window_set_title(GTK_WINDOW(window), "Ksiegarnia - Projekt");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  gtk_tree_view_column_add_attribute(cx3,cr3,"text",0);
  gtk_tree_view_column_add_attribute(cx2,cr2,"text",1);

  populate(&magazyn, treeStore);

  gtk_tree_view_set_model(GTK_TREE_VIEW(tv1), GTK_TREE_MODEL(treeStore));
  
  textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));

  gtk_widget_show_all(window);

  gtk_main();

  return EXIT_SUCCESS;
}

int findRow(GtkTreeModel *model, GtkTreeIter iter, const gchar *srch){
  const gchar *text;
  GtkTreePath *path;

  while (1)
  {
    gtk_tree_model_get(model, &iter,0, &text, -1);
    rowNbr++;

    if( strncasecmp(text, srch, strlen(srch)) == 0){
      g_print("Found: %d, %s\n", rowNbr, text);
      path = gtk_tree_model_get_path(model,&iter);
      gtk_tree_view_expand_all (tv1);

      gtk_tree_view_scroll_to_cell(tv1,path, NULL, TRUE, 0.5,0.0);

      gtk_tree_view_set_drag_dest_row(tv1,path, GTK_TREE_VIEW_DROP_AFTER);

      gtk_tree_view_set_cursor_on_cell(tv1, path,NULL,NULL, FALSE);
      return 1;
    }

      if( !gtk_tree_model_iter_next(model, &iter)){
        return 0;
      }
    
  }
  
}

void on_search_search_changed(GtkSearchEntry *s){
  const gchar *srch;
  GtkTreeIter iter;

  GtkTreeModel *model = gtk_tree_view_get_model(tv1);

  srch = gtk_entry_get_text(GTK_ENTRY(s));

  if (strlen(srch) == 0) return;

  g_print("Search for: %s\n", srch);

  gtk_tree_model_get_iter_first(model, &iter);

  rowNbr = 0;

  findRow(model,iter, srch);
  
}

void selected(gchar *valueTitle, gchar *valueAuthor, ksiazka **magazyn){
  ksiazka *iterator = *magazyn;
  while (strcmp(iterator->autor, valueAuthor) != 0 || strcmp(iterator->tytul, valueTitle) != 0)

  {
    iterator = iterator->nastepny;
  }
  
  currentlySelected = iterator;

}
void displayCurrentlySelected(){
  char tmp[1000];
  char stringIlosc[20];
  char stringCena[30];

  
  g_print("Currently selected %s %s %d %f\n", currentlySelected->autor,currentlySelected->tytul,currentlySelected->ilosc,currentlySelected->cena);
  
  sprintf(stringIlosc, "%d", currentlySelected->ilosc);
  sprintf(stringCena, "%5.2f", currentlySelected->cena);

  strcat(tmp, "\n");
  strcat(tmp, "Author: \n");
  strcat(tmp, currentlySelected->autor);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Title: \n");
  strcat(tmp, currentlySelected->tytul);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Amount: \n");
  strcat(tmp, stringIlosc);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Price: \n");
  strcat(tmp, stringCena);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Description: \n");
  strcat(tmp, currentlySelected->opis);
  printf("Inserting text: %s\n", tmp);
  char *autorPosition = strstr(tmp, "Author");

    // If "Autor" is found, remove the text before it
    if (autorPosition != NULL) {
        // Calculate the length of the text to be removed
        size_t removeLength = autorPosition - tmp;

        // Remove the text by shifting the remaining part to the beginning
        memmove(tmp, autorPosition, strlen(autorPosition) + 1);
    } else {
        // "Autor" not found, handle the case accordingly
        printf("The word 'Autor' not found in the string.\n");
    }

  gtk_text_buffer_set_text(textBuffer, (const gchar *) tmp, (gint) -1);
  strcpy(tmp,"");
}
void on_select_changed(GtkWidget *c){
  gchar *valueTitle;
  gchar *valueAuthor;
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *tmp;

  if (gtk_tree_selection_get_selected (GTK_TREE_SELECTION(c), &model, &iter) == FALSE){
    return;
  }
  gtk_tree_model_get(model,&iter,0,&valueTitle, -1);
  
  gtk_tree_model_get(model,&iter,1,&valueAuthor, -1);

  selected(valueTitle, valueAuthor, &magazyn);

  displayCurrentlySelected();

  
}

void on_buttonNowy_clicked(GtkButton *b){
  //addButton new window
  openWindowNew();
  gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
}

void on_buttonUsun_clicked(GtkButton *b){
  builderDelete = gtk_builder_new_from_file("part3.glade");
  windowDelete = GTK_WIDGET(gtk_builder_get_object(builderDelete, "windowDelete"));
 
  g_signal_connect(windowDelete, "destroy", G_CALLBACK(on_destroy), NULL);

  gtk_builder_connect_signals(builderDelete, NULL);
  fixed3 = GTK_WIDGET(gtk_builder_get_object(builderDelete, "fixed3"));
  labelDeleteAuthor = GTK_WIDGET(gtk_builder_get_object(builderDelete, "labelDeleteAuthor"));
  labelDeleteTitle = GTK_WIDGET(gtk_builder_get_object(builderDelete, "labelDeleteTitle"));
  buttonDeleteNo = GTK_WIDGET(gtk_builder_get_object(builderDelete, "buttonDeleteNo"));
  buttonDeleteYes = GTK_WIDGET(gtk_builder_get_object(builderDelete, "buttonDeleteYes"));

  gtk_window_set_title(GTK_WINDOW(windowDelete), "Deleting a book");
  gtk_window_set_position(GTK_WINDOW(windowDelete), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(windowDelete), FALSE);

  if(currentlySelected != NULL){
    gtk_label_set_text (GTK_LABEL(labelDeleteAuthor), (const gchar*) currentlySelected->autor);
    gtk_label_set_text (GTK_LABEL(labelDeleteTitle), (const gchar*) currentlySelected->tytul);
  }
  gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
    gtk_widget_show_all(windowDelete);
}
void on_buttonEdycja_clicked(GtkButton *b){

  openWindowModify();
  gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
}

void on_buttonPromocja_clicked(GtkButton *b){
  char stringCena[30];

  builderDiscount = gtk_builder_new_from_file("part5.glade");
  windowDiscount = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "windowDiscount"));
 
  g_signal_connect(windowDiscount, "destroy", G_CALLBACK(on_destroy), NULL);

  gtk_builder_connect_signals(builderDiscount, NULL);
  fixed5 = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "fixed5"));
  labelDiscountAuthor = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "labelDiscountAuthor"));
  labelDiscountTitle = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "labelDiscountTitle"));
  labelDiscountPrice = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "labelDiscountPrice"));

  buttonDiscountCancel = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "buttonDiscountCancel"));
  buttonDiscountConfirm = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "buttonDiscountConfirm"));
  
  viewDiscountPercent = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "viewDiscountPercent"));
  entryDiscountPercent = GTK_WIDGET(gtk_builder_get_object(builderDiscount, "entryDiscountPercent"));

  gtk_window_set_title(GTK_WINDOW(windowDiscount), "Discounting a book");
  gtk_window_set_position(GTK_WINDOW(windowDiscount), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(windowDiscount), FALSE);

  if(currentlySelected != NULL){
    sprintf(stringCena, "%5.2f", currentlySelected->cena);

    gtk_label_set_text (GTK_LABEL(labelDiscountAuthor), (const gchar*) currentlySelected->autor);
    gtk_label_set_text (GTK_LABEL(labelDiscountTitle), (const gchar*) currentlySelected->tytul);
    gtk_label_set_text (GTK_LABEL(labelDiscountPrice), (const gchar*) stringCena);
  }

  gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
    gtk_widget_show_all(windowDiscount);

}
void on_buttonSprzedaz_clicked(GtkButton *b){
  char stringIlosc[30];

  builderSell = gtk_builder_new_from_file("part6.glade");
  windowSell = GTK_WIDGET(gtk_builder_get_object(builderSell, "windowSell"));
 
  g_signal_connect(windowSell, "destroy", G_CALLBACK(on_destroy), NULL);

  gtk_builder_connect_signals(builderSell, NULL);
  fixed6 = GTK_WIDGET(gtk_builder_get_object(builderSell, "fixed6"));
  labelSellAuthor = GTK_WIDGET(gtk_builder_get_object(builderSell, "labelSellAuthor"));
  labelSellTitle = GTK_WIDGET(gtk_builder_get_object(builderSell, "labelSellTitle"));
  labelSellAmount = GTK_WIDGET(gtk_builder_get_object(builderSell, "labelSellAmount"));

  buttonSellCancel = GTK_WIDGET(gtk_builder_get_object(builderSell, "buttonSellCancel"));
  buttonSellConfirm = GTK_WIDGET(gtk_builder_get_object(builderSell, "buttonDSellConfirm"));
  
  viewSellAmount = GTK_WIDGET(gtk_builder_get_object(builderSell, "viewSellAmount"));
  entrySellAmount = GTK_WIDGET(gtk_builder_get_object(builderSell, "entrySellAmount"));

  gtk_window_set_title(GTK_WINDOW(windowSell), "Selling a book");
  gtk_window_set_position(GTK_WINDOW(windowSell), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(windowSell), FALSE);

  if(currentlySelected != NULL){
    sprintf(stringIlosc, "%d", currentlySelected->ilosc);

    gtk_label_set_text (GTK_LABEL(labelSellAuthor), (const gchar*) currentlySelected->autor);
    gtk_label_set_text (GTK_LABEL(labelSellTitle), (const gchar*) currentlySelected->tytul);
    gtk_label_set_text (GTK_LABEL(labelSellAmount), (const gchar*) stringIlosc);
  }

  gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
    gtk_widget_show_all(windowSell);

}

void on_buttonDostawa_clicked(GtkButton *b){
  char stringIlosc[30];

  builderDelivery = gtk_builder_new_from_file("part7.glade");
  windowDelivery = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "windowDelivery"));
 
  g_signal_connect(windowDelivery, "destroy", G_CALLBACK(on_destroy), NULL);

  gtk_builder_connect_signals(builderDelivery, NULL);
  fixed7 = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "fixed7"));
  labelDeliveryAuthor = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "labelDeliveryAuthor"));
  labelDeliveryTitle = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "labelDeliveryTitle"));
  labelDeliveryAmount = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "labelDeliveryAmount"));

  buttonDeliveryCancel = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "buttonDeliveryCancel"));
  buttonDeliveryConfirm = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "buttonDeliveryConfirm"));
  
  viewDeliveryAmount = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "viewDeliveryAmount"));
  entryDeliveryAmount = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "entryDeliveryAmount"));

  gtk_window_set_title(GTK_WINDOW(windowDelivery), "Deliverying a book");
  gtk_window_set_position(GTK_WINDOW(windowDelivery), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(windowDelivery), FALSE);

  if(currentlySelected != NULL){
    sprintf(stringIlosc, "%d", currentlySelected->ilosc);

    gtk_label_set_text (GTK_LABEL(labelDeliveryAuthor), (const gchar*) currentlySelected->autor);
    gtk_label_set_text (GTK_LABEL(labelDeliveryTitle), (const gchar*) currentlySelected->tytul);
    gtk_label_set_text (GTK_LABEL(labelDeliveryAmount), (const gchar*) stringIlosc);
  }

  gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
    gtk_widget_show_all(windowDelivery);
  
}