#include <gtk/gtk.h>
GtkWidget *windowModify;
GtkWidget *fixed4;
GtkWidget *buttonModifyEdytuj;
GtkWidget *buttonModifyAnuluj;
GtkWidget *viewModifyTitle;
GtkWidget *viewModifyAuthor;
GtkWidget *viewModifyPrice;
GtkWidget *viewModifyDesc;
GtkWidget *errorModifyLabel;
GtkWidget *entryModifyTitle;
GtkWidget *entryModifyAuthor;
GtkWidget *entryModifyPrice;
GtkWidget *entryModifyDesc;
GtkBuilder *builderModify;


void openWindowModify(){
builderModify = gtk_builder_new_from_file("part4.glade");
  windowModify = GTK_WIDGET(gtk_builder_get_object(builderModify, "windowModify"));
 
  g_signal_connect(windowModify, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(builderModify, NULL);
  fixed4 = GTK_WIDGET(gtk_builder_get_object(builderModify, "fixed4"));
  viewModifyTitle = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyTitle"));
  viewModifyAuthor = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyAuthor"));
  viewModifyPrice = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyPrice"));
  viewModifyDesc = GTK_WIDGET(gtk_builder_get_object(builderModify, "viewModifyDesc"));
  buttonModifyAnuluj = GTK_WIDGET(gtk_builder_get_object(builderModify, "buttonModifyAnuluj"));
  buttonModifyEdytuj = GTK_WIDGET(gtk_builder_get_object(builderModify, "buttonModifyEdytuj"));
  errorModifyLabel = GTK_WIDGET(gtk_builder_get_object(builderModify, "errorModifyLabel"));
  entryModifyAuthor = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyAuthor"));
  entryModifyDesc = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyDesc"));
  entryModifyPrice = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyPrice"));
  entryModifyTitle = GTK_WIDGET(gtk_builder_get_object(builderModify, "entryModifyTitle"));

  gtk_window_set_title(GTK_WINDOW(windowModify), "Modifying the book");
  gtk_window_set_position(GTK_WINDOW(windowModify), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable(GTK_WINDOW(windowModify), FALSE);
  
    gtk_widget_show_all(windowModify);
}