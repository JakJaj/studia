#include <gtk/gtk.h>
GtkWidget *windowAdd;
GtkWidget *fixed2;
GtkWidget *buttonAddDodaj;
GtkWidget *buttonAddAnuluj;
GtkWidget *viewAddTitle;
GtkWidget *viewAddAuthor;
GtkWidget *viewAddAmount;
GtkWidget *viewAddPrice;
GtkWidget *viewAddDesc;
GtkWidget *errorLabel;
GtkWidget *entryAddTitle;
GtkWidget *entryAddAuthor;
GtkWidget *entryAddAmount;
GtkWidget *entryAddPrice;
GtkWidget *entryAddDesc;
GtkBuilder *builderAdd;

void openWindowNew(){
builderAdd = gtk_builder_new_from_file("part2.glade");
  windowAdd = GTK_WIDGET(gtk_builder_get_object(builderAdd, "windowAdd"));
 
  g_signal_connect(windowAdd, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(builderAdd, NULL);
  fixed2 = GTK_WIDGET(gtk_builder_get_object(builderAdd, "fixed2"));
  viewAddTitle = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddTitle"));
  viewAddAuthor = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddAuthor"));
  viewAddAmount = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddAmount"));
  viewAddPrice = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddPrice"));
  viewAddDesc = GTK_WIDGET(gtk_builder_get_object(builderAdd, "viewAddDesc"));
  buttonAddAnuluj = GTK_WIDGET(gtk_builder_get_object(builderAdd, "buttonAddAnuluj"));
  buttonAddDodaj = GTK_WIDGET(gtk_builder_get_object(builderAdd, "buttonAddDodaj"));
  errorLabel = GTK_WIDGET(gtk_builder_get_object(builderAdd, "errorLabel"));
  entryAddAmount = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddAmount"));
  entryAddAuthor = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddAuthor"));
  entryAddDesc = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddDesc"));
  entryAddPrice = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddPrice"));
  entryAddTitle = GTK_WIDGET(gtk_builder_get_object(builderAdd, "entryAddTitle"));

  gtk_window_set_title(GTK_WINDOW(windowAdd), "Adding the book");
  gtk_window_set_position(GTK_WINDOW(windowAdd), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(windowAdd), FALSE);
  
    gtk_widget_show_all(windowAdd);
}