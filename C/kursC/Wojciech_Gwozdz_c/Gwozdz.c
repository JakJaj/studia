#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

typedef struct Ksiazka {
    char autor[100];
    char tytul[100];
    double cena;
    int ilosc;
    struct Ksiazka *nastepna;
} Ksiazka;

Ksiazka *pierwsza = NULL;
GtkWidget *etykietaStatusu;
GtkWidget *wpisAutora, *wpisTytulu, *wpisCeny, *wpisIlosci;
GtkWidget *widokKsiazek;

void aktualizujWidokKsiazek() {
    GString *ksiazki = g_string_new("");
    for (Ksiazka *iter = pierwsza; iter != NULL; iter = iter->nastepna) {
        g_string_append_printf(ksiazki, "Autor: %s, Tytul: %s, Cena: %.2f, Ilosc: %d\n", iter->autor, iter->tytul, iter->cena, iter->ilosc);
    }
    gtk_label_set_text(GTK_LABEL(widokKsiazek), ksiazki->str);
    g_string_free(ksiazki, TRUE);
}

void dodajKsiazke(const char *autor, const char *tytul, double cena, int ilosc) {
    for (Ksiazka *iter = pierwsza; iter != NULL; iter = iter->nastepna) {
        if (strcmp(iter->tytul, tytul) == 0 && strcmp(iter->autor, autor) == 0) {
            iter->ilosc += ilosc;
            aktualizujWidokKsiazek();
            return;
        }
    }
    Ksiazka *nowa = (Ksiazka *)malloc(sizeof(Ksiazka));
    strcpy(nowa->autor, autor);
    strcpy(nowa->tytul, tytul);
    nowa->cena = cena;
    nowa->ilosc = ilosc;
    nowa->nastepna = pierwsza;
    pierwsza = nowa;
    aktualizujWidokKsiazek();
}

void usunKsiazke(const char *tytul) {
    Ksiazka *aktualna = pierwsza;
    Ksiazka *poprzednia = NULL;
    while (aktualna != NULL) {
        if (strcmp(aktualna->tytul, tytul) == 0) {
            if (aktualna->ilosc > 1) {
                aktualna->ilosc--;
            } else {
                if (poprzednia == NULL) {
                    pierwsza = aktualna->nastepna;
                } else {
                    poprzednia->nastepna = aktualna->nastepna;
                }
                free(aktualna);
            }
            aktualizujWidokKsiazek();
            return;
        }
        poprzednia = aktualna;
        aktualna = aktualna->nastepna;
    }
}

Ksiazka *znajdzKsiazkePoTytule(const char *tytul) {
    for (Ksiazka *iter = pierwsza; iter != NULL; iter = iter->nastepna) {
        if (strcmp(iter->tytul, tytul) == 0) {
            return iter;
        }
    }
    return NULL;
}

void znajdzKsiazkiPoAutorze(const char *autor) {
    GString *ksiazki = g_string_new("");
    for (Ksiazka *iter = pierwsza; iter != NULL; iter = iter->nastepna) {
        if (strcmp(iter->autor, autor) == 0) {
            g_string_append_printf(ksiazki, "Autor: %s, Tytul: %s, Cena: %.2f, Ilosc: %d\n",
                                   iter->autor, iter->tytul, iter->cena, iter->ilosc);
        }
    }

    if (ksiazki->len > 0) {  
        gtk_label_set_text(GTK_LABEL(widokKsiazek), ksiazki->str);
    } else {
        gtk_label_set_text(GTK_LABEL(widokKsiazek), "Nie znaleziono ksiazek danego autora.");
    }

    g_string_free(ksiazki, TRUE);
}



static void pokazWszystkieKsiazki(GtkWidget *widget, gpointer data) {
    aktualizujWidokKsiazek();
}

static void dodajKsiazkeCallback(GtkWidget *widget, gpointer data) {
    const char *autor = gtk_entry_get_text(GTK_ENTRY(wpisAutora));
    const char *tytul = gtk_entry_get_text(GTK_ENTRY(wpisTytulu));
    const char *cena_str = gtk_entry_get_text(GTK_ENTRY(wpisCeny));
    const char *ilosc_str = gtk_entry_get_text(GTK_ENTRY(wpisIlosci));
    double cena = atof(cena_str);
    int ilosc = atoi(ilosc_str);

    dodajKsiazke(autor, tytul, cena, ilosc);
}

static void usunKsiazkeCallback(GtkWidget *widget, gpointer data) {
    const char *tytul = gtk_entry_get_text(GTK_ENTRY(wpisTytulu));
    usunKsiazke(tytul);
}

static void szukajPoAutorzeCallback(GtkWidget *widget, gpointer data) {
    const char *autor = gtk_entry_get_text(GTK_ENTRY(wpisAutora));
    znajdzKsiazkiPoAutorze(autor);
}

static void szukajPoTytuleCallback(GtkWidget *widget, gpointer data) {
    const char *tytul = gtk_entry_get_text(GTK_ENTRY(wpisTytulu));
    Ksiazka *znaleziona = znajdzKsiazkePoTytule(tytul);
    GString *ksiazki = g_string_new("");
    if (znaleziona) {
        g_string_append_printf(ksiazki, "Znaleziono ksiazke: Autor: %s, Tytul: %s, Cena: %.2f, Ilosc: %d\n", znaleziona->autor, znaleziona->tytul, znaleziona->cena, znaleziona->ilosc);
    } else {
        g_string_append(ksiazki, "Nie znaleziono ksiazki o podanym tytule.");
    }
    gtk_label_set_text(GTK_LABEL(widokKsiazek), ksiazki->str);
    g_string_free(ksiazki, TRUE);
}

// Funkcja inicjalizująca interfejs użytkownika
static void uruchom(GtkApplication *app, gpointer user_data) {
    GtkWidget *okno;
    GtkWidget *siatka;
    GtkWidget *przyciskDodaj, *przyciskUsun, *przyciskSzukajPoAutorze, *przyciskSzukajPoTytule, *przyciskPokazWszystkie;
    GtkWidget *etykietaAutor, *etykietaTytul, *etykietaCena, *etykietaIlosc;

    okno = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(okno), "Księgarnia");
    gtk_window_set_default_size(GTK_WINDOW(okno), 300, 200);

    siatka = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(okno), siatka);

    etykietaAutor = gtk_label_new("Autor:");
    gtk_grid_attach(GTK_GRID(siatka), etykietaAutor, 0, 0, 1, 1);
    wpisAutora = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(siatka), wpisAutora, 1, 0, 1, 1);

    etykietaTytul = gtk_label_new("Tytuł:");
    gtk_grid_attach(GTK_GRID(siatka), etykietaTytul, 0, 1, 1, 1);
    wpisTytulu = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(siatka), wpisTytulu, 1, 1, 1, 1);

    etykietaCena = gtk_label_new("Cena:");
    gtk_grid_attach(GTK_GRID(siatka), etykietaCena, 0, 2, 1, 1);
    wpisCeny = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(siatka), wpisCeny, 1, 2, 1, 1);

    etykietaIlosc = gtk_label_new("Ilość:");
    gtk_grid_attach(GTK_GRID(siatka), etykietaIlosc, 0, 3, 1, 1);
    wpisIlosci = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(siatka), wpisIlosci, 1, 3, 1, 1);

    przyciskDodaj = gtk_button_new_with_label("Dodaj książkę");
    g_signal_connect(przyciskDodaj, "clicked", G_CALLBACK(dodajKsiazkeCallback), NULL);
    gtk_grid_attach(GTK_GRID(siatka), przyciskDodaj, 0, 4, 2, 1);

    przyciskUsun = gtk_button_new_with_label("Usuń książkę");
    g_signal_connect(przyciskUsun, "clicked", G_CALLBACK(usunKsiazkeCallback), NULL);
    gtk_grid_attach(GTK_GRID(siatka), przyciskUsun, 0, 5, 2, 1);

    przyciskSzukajPoAutorze = gtk_button_new_with_label("Szukaj po autorze");
    g_signal_connect(przyciskSzukajPoAutorze, "clicked", G_CALLBACK(szukajPoAutorzeCallback), NULL);
    gtk_grid_attach(GTK_GRID(siatka), przyciskSzukajPoAutorze, 0, 6, 2, 1);

    przyciskSzukajPoTytule = gtk_button_new_with_label("Szukaj po tytule");
    g_signal_connect(przyciskSzukajPoTytule, "clicked", G_CALLBACK(szukajPoTytuleCallback), NULL);
    gtk_grid_attach(GTK_GRID(siatka), przyciskSzukajPoTytule, 0, 7, 2, 1);

    przyciskPokazWszystkie = gtk_button_new_with_label("Pokaż wszystkie książki");
    g_signal_connect(przyciskPokazWszystkie, "clicked", G_CALLBACK(pokazWszystkieKsiazki), NULL);
    gtk_grid_attach(GTK_GRID(siatka), przyciskPokazWszystkie, 0, 8, 2, 1);

    widokKsiazek = gtk_label_new(NULL);
    gtk_label_set_justify(GTK_LABEL(widokKsiazek), GTK_JUSTIFY_LEFT);
    gtk_grid_attach(GTK_GRID(siatka), widokKsiazek, 0, 9, 2, 1);

    gtk_widget_show_all(okno);

    aktualizujWidokKsiazek();
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example.ksiegarnia", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(uruchom), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    while (pierwsza != NULL) {
        Ksiazka *temp = pierwsza;
        pierwsza = pierwsza->nastepna;
        free(temp);
    }

    return status;
}



