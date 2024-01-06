#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include "structure.h"
#define ZA_MALO_PAMIECI 0

//main window
GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *buttonNew;
GtkWidget *buttonDelete;
GtkWidget *buttonModify;
GtkWidget *buttonSell;
GtkWidget *buttonDelivery;
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

//add window
GtkWidget *windowAdd;
GtkWidget *fixed2;
GtkWidget *buttonAddAdd;
GtkWidget *buttonAddCancel;
GtkWidget *viewAddTitle;
GtkWidget *viewAddAuthor;
GtkWidget *viewAddAmount;
GtkWidget *viewAddPrice;
GtkWidget *viewAddDesc;
GtkWidget *errorAddLabel;
GtkWidget *entryAddTitle;
GtkWidget *entryAddAuthor;
GtkWidget *entryAddAmount;
GtkWidget *entryAddPrice;
GtkWidget *entryAddDesc;
GtkBuilder *builderAdd;

//delete window
GtkWidget *windowDelete;
GtkWidget *fixed3;
GtkWidget *buttonDeleteNo;
GtkWidget *buttonDeleteYes;
GtkWidget *labelDeleteAuthor;
GtkWidget *labelDeleteTitle;
GtkBuilder *builderDelete;

//modify window
GtkWidget *windowModify;
GtkWidget *fixed4;
GtkWidget *buttonModifyModify;
GtkWidget *buttonModifyCancel;
GtkWidget *viewModifyTitle;
GtkWidget *viewModifyAuthor;
GtkWidget *viewModifyPrice;
GtkWidget *viewModifyDesc;
GtkWidget *viewModifyAmount;
GtkWidget *errorModifyLabel;
GtkWidget *entryModifyTitle;
GtkWidget *entryModifyAmount;
GtkWidget *entryModifyAuthor;
GtkWidget *entryModifyPrice;
GtkWidget *entryModifyDesc;
GtkBuilder *builderModify;

//discount window
GtkWidget *windowDiscount;
GtkWidget *fixed5;
GtkWidget *buttonDiscountCancel;
GtkWidget *buttonDiscountConfirm;
GtkWidget *labelDiscountAuthor;
GtkWidget *labelDiscountTitle;
GtkWidget *labelDiscountPrice;
GtkWidget *errorDiscountLabel;
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
GtkWidget *errorSellLabel;
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
GtkWidget *errorDeliveryLabel;
GtkWidget *entryDeliveryAmount;
GtkWidget *viewDeliveryAmount;
GtkBuilder *builderDelivery;

int is_float(const char *s) {
    char *end;
    errno = 0;

    double val = strtod(s, &end);

    if (errno == ERANGE) return 0;
    if (end == s) return 0;
    if (*end != '\0') return 0;

    return 1;
}

void populate(book **storage, GtkTreeStore *treeStore) {
  book *iterator = *storage;
  currentlySelected = *storage;

  GtkTreeIter iter;
  
  while (iterator != NULL) {
    g_print("Setting data: Title=%s, Autor=%s\n", iterator->title, iterator->author);
    gtk_tree_store_append(treeStore, &iter, NULL);

    gtk_tree_store_set(treeStore, &iter, 0, iterator->title, -1);
    gtk_tree_store_set(treeStore, &iter, 1, iterator->author, -1);
  
    iterator = iterator->next;
  }
  g_print("\n");
  gtk_widget_show_all(window);
}

void saveToFile(book **storage, FILE *file){
  book *iterator = *storage;
  int i = 0;
  while (iterator != NULL) {
    fprintf(file, "%s;%s;%d;%f;%s", iterator->title, iterator->author, iterator->amount, iterator->price, iterator->description);
    if (i != amountOfBooks) fprintf(file, "\n");
    else if (i == amountOfBooks)
    ; //do nothing
    i++;
    iterator = iterator->next;
  }
}

void on_destroy(){
  //save items to file!
  g_print("Saving curent state to file\n");
  FILE *file = fopen ("books.txt", "w");
  
  if (file == NULL) { //would never happen i guess
       g_print("No such file\n");
       g_print("Creating a new one\n");
       exit(1);
    }

  saveToFile(&storage, file);

  g_print("Closing the program\n");
  gtk_main_quit();
}

int main (int argc, char *argv[]){
  
  char fileName[15] = "books.txt";
  
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
      printf("Error opening file\n");
      exit(1);
    }
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) {
      printf("Empty file\n");
      exit(1);
    }

    rewind(fp);

  bool success = wypelnijMagazyn(fileName, &storage);

  gtk_init(&argc, &argv);

  builder = gtk_builder_new_from_file("Glade/main.glade");
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
  buttonNew = GTK_WIDGET(gtk_builder_get_object(builder, "buttonNew"));
  buttonDelete = GTK_WIDGET(gtk_builder_get_object(builder, "buttonDelete"));
  buttonModify = GTK_WIDGET(gtk_builder_get_object(builder, "buttonModify"));
  buttonSell = GTK_WIDGET(gtk_builder_get_object(builder, "buttonSell"));
  buttonDelivery = GTK_WIDGET(gtk_builder_get_object(builder, "buttonDelivery"));
  search = GTK_WIDGET(gtk_builder_get_object(builder, "search"));
  textView = GTK_WIDGET(gtk_builder_get_object(builder, "textView"));

  gtk_window_set_title(GTK_WINDOW(window), "Bookstore - Project");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  gtk_tree_view_column_add_attribute(cx3,cr3,"text",0);
  gtk_tree_view_column_add_attribute(cx2,cr2,"text",1);

  populate(&storage, treeStore);

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

void selected(gchar *valueTitle, gchar *valueAuthor, book **storage){
  book *iterator = *storage;
  while (strcmp(iterator->author, valueAuthor) != 0 || strcmp(iterator->title, valueTitle) != 0)
  {
    iterator = iterator->next;
  }
  currentlySelected = iterator;
}

void deleteLettersBeforeAuthor(char* word) {
  char* author = strstr(word, "Author");
  if (author != NULL) {
    memmove(word, author, strlen(author) + 1);
  }
}

void displayCurrentlySelected(){
  char tmp[1000];
  char stringAmount[20];
  char stringPrice[30];

  g_print("Currently selected %s %s %d %f\n", 
  currentlySelected->author,currentlySelected->title,currentlySelected->amount,currentlySelected->price);
  
  sprintf(stringAmount, "%d", currentlySelected->amount);
  sprintf(stringPrice, "%5.2f", currentlySelected->price);

  strcat(tmp, "\n");
  strcat(tmp, "Author: \n");
  strcat(tmp, currentlySelected->author);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Title: \n");
  strcat(tmp, currentlySelected->title);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Amount: \n");
  strcat(tmp, stringAmount);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Price: \n");
  strcat(tmp, stringPrice);
  strcat(tmp, "\n");
  strcat(tmp, "\n");
  strcat(tmp, "Description: \n");
  strcat(tmp, currentlySelected->description);
  deleteLettersBeforeAuthor(tmp);
  gtk_text_buffer_set_text(textBuffer, tmp, -1);
}

  // Function to handle the selection change event in the GTK tree view
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

    selected(valueTitle, valueAuthor, &storage);

    displayCurrentlySelected();
  }

void on_subwindow_destroy(GtkWidget *subwindow){
  g_print("Subwindow closed\n");
  gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
  gtk_widget_destroy(subwindow);
}

  // Function to handle the "New" button click event
  void on_buttonNew_clicked(GtkButton *b){
    builderAdd = gtk_builder_new_from_file("Glade/new.glade");
    windowAdd = GTK_WIDGET(gtk_builder_get_object(builderAdd, "windowAdd"));
   
    g_signal_connect(windowAdd, "destroy", G_CALLBACK(on_subwindow_destroy), NULL);

    gtk_builder_connect_signals(builderAdd, NULL);
    fixed2 = GTK_WIDGET(gtk_builder_get_object(builderAdd, "fixed2"));
    viewAddTitle = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddTitle"));
    viewAddAuthor = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddAuthor"));
    viewAddAmount = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddAmount"));
    viewAddPrice = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddPrice"));
    viewAddDesc = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddDesc"));
    buttonAddCancel = GTK_WIDGET(gtk_builder_get_object(builderAdd, "buttonAddCancel"));
    buttonAddAdd = GTK_WIDGET(gtk_builder_get_object(builderAdd, "buttonAddAdd"));
    errorAddLabel = GTK_WIDGET(gtk_builder_get_object(builderAdd, "errorAddLabel"));
    entryAddAmount = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddAmount"));
    entryAddAuthor = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddAuthor"));
    entryAddDesc = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddDesc"));
    entryAddPrice = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddPrice"));
    entryAddTitle = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddTitle"));

    gtk_window_set_title(GTK_WINDOW(windowAdd), "Adding the book");
    gtk_window_set_position(GTK_WINDOW(windowAdd), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(windowAdd), FALSE);
    
    gtk_widget_show_all(windowAdd);
    gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
  }

  void on_buttonAddAdd_clicked(GtkButton *b){  
    const gchar *title = gtk_entry_get_text(GTK_ENTRY(entryAddTitle));
    const gchar *author = gtk_entry_get_text(GTK_ENTRY(entryAddAuthor));
    const gchar *amount = gtk_entry_get_text(GTK_ENTRY(entryAddAmount));
    const gchar *price = gtk_entry_get_text(GTK_ENTRY(entryAddPrice));
    const gchar *desc = gtk_entry_get_text(GTK_ENTRY(entryAddDesc));
    book *new = (book*)malloc(sizeof(book));

    if(isalnum((unsigned char) *title)){
      new->title = strdup(title);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorAddLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryAddTitle), (const gchar*) "");
      g_print("Incorect title!\n");
      return;
    }
    if(isalpha((unsigned char) *author)){
      new->author = strdup(author);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorAddLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryAddAuthor), (const gchar*) "");
      g_print("Incorect author!\n");
      return;
    }
    if(isdigit((unsigned char) *amount)){
      new->amount = atoi(amount);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorAddLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryAddAmount), (const gchar*) "");
      g_print("Incorect amount!\n");
      return;
    }
    if(isdigit((unsigned char) *price) || is_float(price)){
      new->price = atof(price);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorAddLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryAddPrice), (const gchar*) "");
      g_print("Incorect price!\n");
      return;
    }
    if(isalnum((unsigned char) *desc)){
      new->description = strdup(desc);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorAddLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryAddDesc), (const gchar*) "");
      g_print("Incorect description!\n");
      return;
    }
    new->next = NULL;
    push_back(new, &storage);
    
    GtkTreeIter iter;

    gtk_tree_store_append(treeStore, &iter, NULL);

    gtk_tree_store_set(treeStore, &iter, 0, new->title, -1);
    gtk_tree_store_set(treeStore, &iter, 1, new->author, -1);
    
    GtkTreeViewColumn *column = gtk_tree_view_get_column(tv1, amountOfBooks);
    gtk_tree_view_set_cursor(tv1, gtk_tree_model_get_path(GTK_TREE_MODEL(treeStore), &iter), column, FALSE);
    g_print("Added: %s %s %d %f\n", new->author, new->title, new->amount, new->price);
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowAdd);

  }

  void on_buttonAddCancel_clicked(GtkButton *b){
    g_print("Adding canceled\n");
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowAdd);
  }

  // Function to handle the "Delete" button click event
  void on_buttonDelete_clicked(GtkButton *b){
    builderDelete = gtk_builder_new_from_file("Glade/delete.glade");
    windowDelete = GTK_WIDGET(gtk_builder_get_object(builderDelete, "windowDelete"));
   
    g_signal_connect(windowDelete, "destroy", G_CALLBACK(on_subwindow_destroy), NULL);

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
      gtk_label_set_text (GTK_LABEL(labelDeleteAuthor), (const gchar*) currentlySelected->author);
      gtk_label_set_text (GTK_LABEL(labelDeleteTitle), (const gchar*) currentlySelected->title);
    }
    gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
      gtk_widget_show_all(windowDelete);
  }

  void on_buttonDeleteYes_clicked(GtkButton *b){
    GtkTreeIter iter;
    GtkTreeModel *model;

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
      deleteBook(&storage, currentlySelected);
      gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
      g_print("Deleted: %s %s %d %f\n", currentlySelected->author, currentlySelected->title, currentlySelected->amount, currentlySelected->price);
    }
    
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowDelete);
  }

  void on_buttonDeleteNo_clicked(GtkButton *b){
    g_print("Deleting canceled\n");
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowDelete);
  }

  // Function to handle the "Modify" button click event
  void on_buttonModify_clicked(GtkButton *b){

    builderModify = gtk_builder_new_from_file("Glade/modify.glade");
    windowModify = GTK_WIDGET(gtk_builder_get_object(builderModify, "windowModify"));
   
    g_signal_connect(windowModify, "destroy", G_CALLBACK(on_subwindow_destroy), NULL);

    gtk_builder_connect_signals(builderModify, NULL);
    fixed4 = GTK_WIDGET(gtk_builder_get_object(builderModify, "fixed4"));
    viewModifyTitle = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyTitle"));
    viewModifyAuthor = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyAuthor"));
    viewModifyPrice = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyPrice"));
    viewModifyDesc = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyDesc"));
    viewModifyAmount = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyAmount"));
    buttonModifyCancel = GTK_WIDGET(gtk_builder_get_object(builderModify, "buttonModifyCancel"));
    buttonModifyModify = GTK_WIDGET(gtk_builder_get_object(builderModify, "buttonModifyModify"));
    errorModifyLabel = GTK_WIDGET(gtk_builder_get_object(builderModify, "errorModifyLabel"));
    entryModifyAuthor = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyAuthor"));
    entryModifyDesc = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyDesc"));
    entryModifyAmount = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyAmount"));
    entryModifyPrice = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyPrice"));
    entryModifyTitle = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyTitle"));

    gtk_window_set_title(GTK_WINDOW(windowModify), "Modifying the book");
    gtk_window_set_position(GTK_WINDOW(windowModify), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(windowModify), FALSE);
    
    gtk_widget_show_all(windowModify);
    gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
  }

  void on_buttonModifyModify_clicked(GtkButton *b){
    const gchar *title = gtk_entry_get_text(GTK_ENTRY(entryModifyTitle));
    const gchar *author = gtk_entry_get_text(GTK_ENTRY(entryModifyAuthor));
    const gchar *price = gtk_entry_get_text(GTK_ENTRY(entryModifyPrice));
    const gchar *amount = gtk_entry_get_text(GTK_ENTRY(entryModifyAmount));
    const gchar *desc = gtk_entry_get_text(GTK_ENTRY(entryModifyDesc));
    GtkTreeIter iter;
    GtkTreeModel *model;

    if(title[0] == '\0'){
      //do nothing
    }
    else if(isalnum((unsigned char) *title)){
      currentlySelected->title = strdup(title);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorModifyLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryModifyTitle), (const gchar*) "");
      g_print("Incorect title!\n");
      return;
    }
    
    if(author[0] == '\0'){
      //do nothing
    }
    else if(isalpha((unsigned char) *author)){
      currentlySelected->author = strdup(author);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorModifyLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryModifyAuthor), (const gchar*) "");
      g_print("Incorect author!\n");
      return;
    }
    
    if(price[0] == '\0'){
      //do nothing
    }
    else if(isdigit((unsigned char) *price) || is_float(price)){
      currentlySelected->price = atof(price);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorModifyLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryModifyPrice), (const gchar*) "");
      g_print("Incorect price!\n");
      return;
    }

    if(amount[0] == '\0'){
      //do nothing
    }
    else if(isdigit((unsigned char) *amount)){
      currentlySelected->amount = atoi(amount);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorModifyLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryModifyAmount), (const gchar*) "");
      g_print("Incorect amount!\n");
      return;
    }

    if(desc[0] == '\0'){
      //do nothing
    }
    else if(isalnum((unsigned char) *desc)){
      currentlySelected->description = strdup(desc);
    }
    else{
      gtk_label_set_text (GTK_LABEL(errorModifyLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryModifyDesc), (const gchar*) "");
      g_print("Incorect description!\n");
      return;
    }

    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
      gtk_tree_store_set(treeStore, &iter, 0, currentlySelected->title, -1);
      gtk_tree_store_set(treeStore, &iter, 1, currentlySelected->author, -1);
      g_print("Modified: %s %s %d %f\n", currentlySelected->author, currentlySelected->title, currentlySelected->amount, currentlySelected->price);
    }
    
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowModify);

  }

  void on_buttonModifyCancel_clicked(GtkButton *b){
    g_print("Modifying canceled\n");
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowModify);
  }
  
  // Function to handle the "Sell" button click event
  void on_buttonSell_clicked(GtkButton *b){
    char stringAmount[30];

    builderSell = gtk_builder_new_from_file("Glade/sell.glade");
    windowSell = GTK_WIDGET(gtk_builder_get_object(builderSell, "windowSell"));
   
    g_signal_connect(windowSell, "destroy", G_CALLBACK(on_subwindow_destroy), NULL);

    gtk_builder_connect_signals(builderSell, NULL);
    fixed6 = GTK_WIDGET(gtk_builder_get_object(builderSell, "fixed6"));
    labelSellAuthor = GTK_WIDGET(gtk_builder_get_object(builderSell, "labelSellAuthor"));
    labelSellTitle = GTK_WIDGET(gtk_builder_get_object(builderSell, "labelSellTitle"));
    labelSellAmount = GTK_WIDGET(gtk_builder_get_object(builderSell, "labelSellAmount"));
    errorSellLabel = GTK_WIDGET(gtk_builder_get_object(builderSell, "errorSellLabel"));
    buttonSellCancel = GTK_WIDGET(gtk_builder_get_object(builderSell, "buttonSellCancel"));
    buttonSellConfirm = GTK_WIDGET(gtk_builder_get_object(builderSell, "buttonDSellConfirm"));
    
    viewSellAmount = GTK_WIDGET(gtk_builder_get_object(builderSell, "viewSellAmount"));
    entrySellAmount = GTK_WIDGET(gtk_builder_get_object(builderSell, "entrySellAmount"));

    gtk_window_set_title(GTK_WINDOW(windowSell), "Selling a book");
    gtk_window_set_position(GTK_WINDOW(windowSell), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(windowSell), FALSE);

    if(currentlySelected != NULL){
      sprintf(stringAmount, "%d", currentlySelected->amount);

      gtk_label_set_text (GTK_LABEL(labelSellAuthor), (const gchar*) currentlySelected->author);
      gtk_label_set_text (GTK_LABEL(labelSellTitle), (const gchar*) currentlySelected->title);
      gtk_label_set_text (GTK_LABEL(labelSellAmount), (const gchar*) stringAmount);
    }

    gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
      gtk_widget_show_all(windowSell);

  }

  void on_buttonSellConfirm_clicked(GtkButton *b){
    if(!isdigit((unsigned char) *gtk_entry_get_text(GTK_ENTRY(entrySellAmount)))){
      gtk_label_set_text (GTK_LABEL(errorSellLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entrySellAmount), (const gchar*) "");
      g_print("Incorect amount type\n");
      return;
    }
    if(currentlySelected->amount < atoi(gtk_entry_get_text(GTK_ENTRY(entrySellAmount)))){
      gtk_label_set_text (GTK_LABEL(errorSellLabel), (const gchar*) "Not enough books in stock!");
      gtk_entry_set_text (GTK_ENTRY(entrySellAmount), (const gchar*) "");
      g_print("Not enough books in stock!\n");
      return;
    }
    else{
      currentlySelected->amount -= atoi(gtk_entry_get_text(GTK_ENTRY(entrySellAmount)));
      g_print("Sold %d books\n", atoi(gtk_entry_get_text(GTK_ENTRY(entrySellAmount))));
    }
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowSell);
  }

  void on_buttonSellCancel_clicked(GtkButton *b){
    g_print("Selling canceled\n");
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowSell);
  }

  // Function to handle the "Delivery" button click event
  void on_buttonDelivery_clicked(GtkButton *b){
    char stringAmount[30];

    builderDelivery = gtk_builder_new_from_file("Glade/delivery.glade");
    windowDelivery = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "windowDelivery"));
   
    g_signal_connect(windowDelivery, "destroy", G_CALLBACK(on_subwindow_destroy), NULL);

    gtk_builder_connect_signals(builderDelivery, NULL);
    fixed7 = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "fixed7"));
    labelDeliveryAuthor = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "labelDeliveryAuthor"));
    labelDeliveryTitle = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "labelDeliveryTitle"));
    labelDeliveryAmount = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "labelDeliveryAmount"));
    errorDeliveryLabel = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "errorDeliveryLabel"));
    buttonDeliveryCancel = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "buttonDeliveryCancel"));
    buttonDeliveryConfirm = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "buttonDeliveryConfirm"));
    
    viewDeliveryAmount = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "viewDeliveryAmount"));
    entryDeliveryAmount = GTK_WIDGET(gtk_builder_get_object(builderDelivery, "entryDeliveryAmount"));

    gtk_window_set_title(GTK_WINDOW(windowDelivery), "Deliverying a book");
    gtk_window_set_position(GTK_WINDOW(windowDelivery), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(windowDelivery), FALSE);

    if(currentlySelected != NULL){
      sprintf(stringAmount, "%d", currentlySelected->amount);

      gtk_label_set_text (GTK_LABEL(labelDeliveryAuthor), (const gchar*) currentlySelected->author);
      gtk_label_set_text (GTK_LABEL(labelDeliveryTitle), (const gchar*) currentlySelected->title);
      gtk_label_set_text (GTK_LABEL(labelDeliveryAmount), (const gchar*) stringAmount);
    }

    gtk_widget_set_sensitive(GTK_WIDGET(window), FALSE);
      gtk_widget_show_all(windowDelivery);
  }

  void on_buttonDeliveryConfirm_clicked(GtkButton *b){
    if(!isdigit((unsigned char) *gtk_entry_get_text(GTK_ENTRY(entryDeliveryAmount)))){
      gtk_label_set_text (GTK_LABEL(errorDeliveryLabel), (const gchar*) "Incorect data!");
      gtk_entry_set_text (GTK_ENTRY(entryDeliveryAmount), (const gchar*) "");
      g_print("Incorect amount type\n");
      return;
    }
    else{
      currentlySelected->amount += atoi(gtk_entry_get_text(GTK_ENTRY(entryDeliveryAmount)));
      g_print("Delivered %d books\n", atoi(gtk_entry_get_text(GTK_ENTRY(entryDeliveryAmount))));
      gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
      gtk_widget_destroy(windowDelivery);
      g_print("Delivered %d books\n", atoi(gtk_entry_get_text(GTK_ENTRY(entryDeliveryAmount))));
    }
  }

  void on_buttonDeliveryCancel_clicked(GtkButton *b){
    g_print("Deliverying canceled\n");
    gtk_widget_set_sensitive(GTK_WIDGET(window), TRUE);
    gtk_widget_destroy(windowDelivery);
  }