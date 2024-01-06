# Projekt zaliczeniowy - Jakub Jajonek
___

<p>Przesylam caly kod zrodlowy mojego projektu zaliczeniowego z zajec: Kurs C.</p>
<p>Projekt zostal napisany w calosci w jezyku C z wykorzystaniem narzedzia Glade.</p>

### Glade
<p>Podczas poszukwiania zrodel do nauki GTK natrafilem na to narzedzie, bylo ono bardzo pomocne przy projektowaniu GUI. Dzieki niemu proces tworzenia projektu stal sie znacznie przyjemniejszy. A co najwazenijsze, mysle ze dzieki niemu udalo mi sie zaoszczedzic bardzo duzo czasu i jeszcze wiecej nerwow.</p>

[Github - Glade](https://github.com/GNOME/glade)

<p>Glade tworzy pliki o rozszerzeniu .glade (sa to tak naprawde pliki xml) pliki te znajduja sie w folderze Glade/. Folder ten jest niezbedny w folderze w ktorym wykonywany jest projekt gdyz z plikow w nim zawartych pobierany jest schemat calego GUI.</p>

### Makefile
<p>Do skompilowania calego projektu wystarczy wykoniac polecenie:</p>

```sh
make
```
<p>Powstanie wtedy plik wynikowy projekt_Jakub_Jajonek gotowy do wykonania. Przez moj aktualny brak wiedzy nie znalazlem bardziej eleganckiego rozwiazania.</p>

## Podstawowe funkcjonalnosci 

<p>Po wykonaniu pliku projekt_Jakub_Jajonek otworzy sie glowne okno. Zawierajace 5 przyciskow, wyszukiwarke, liste zapisanych ksiazek i panel w ktorym wypisywane beda szczegoly zaznaczonej na liscie ksiazki.</p>

### Przycisk: New
<p>Bez zaskoczen, dzieki temu przyciskowi przenoscimy sie do pod-okna w ktorym wpisujemy informacje o ksiazce ktora dodajemy.</p>
<p>Przy nastepujacych zalozeniach:</p>

* Tytul jest wartoscia alfanumeryczna
* Autor jest wartoscia alfabetyczna
* Liczba jest wartoscia numeryczna (rzutowana na int wiec wartosc po przecinku jest utracona)
* Cena jest wartoscia numeryczna
* Opis jest wartoscia alfanumeryczna

### Przycisk: Delete
<p>Tutaj jedyna rzecza warta odnotowania jest to ze ksiazka brana do usuniecia jest ksiazna aktualnie zaznaczona. Jesli zadna ksiazka nie jest zaznaczona to brana pod uwage jest ksiaza pierwsza.</p>

### Przycisk: Modify
<p>Przycisk przez ktory tak na prawde tworzona jest ta mini dokumentacja.</p> 

<p>Brana do modyfikacji jest ksiazna aktualnie zaznaczona. Jesli zadna ksiazka nie jest zaznaczona to brana pod uwage jest ksiaza pierwsza.</p>

<p><strong>Wpisujemy wartosci tylko w miejsca ktore chcemy zmienic!</strong> </p>
<p>Znaczy to tylko tyle ze puste pola sa polami ktore pozostaja bez zmian. Oczywiscie wpisanie takiej samej wartosci jak wartosc aktualna rowniez nic nie zmieni.</p>

<p>Jesli chcemy zmienic zawartosc to w odpowienie miejsce wpisujemy wartosc ktora oczekujemy po zmianie</p>

<p>Zawartosc kazdego pola podchodzi takim samym zalozenia jak w przypadku przycisku New.</p>

### Przycisk: Sell
<p>Ksiazka brana do sprzedazy zadanej liczby egzemplarzy jest ksiazka zaznaczona w momencie wcisniecia przycisku. Jesli nie zaznaczona nic, brana jest pierwsza ksiazka.</p>

### Przycisk: Delivery
<p>Ksiazka brana do dostawy zadanej liczby egzemplarzy jest ksiazka zaznaczona w momencie wcisniecia przycisku. Jesli nie zaznaczona nic, brana jest pierwsza ksiazka.</p>

### Dodatkowe informacje:
<p>Program nie rozpocznie pracy jezeli w pliku books.txt nie bedzie znajdowala sie zadna ksiazka</p>

<p>Nie znalzalem sposobu na wylaczenie mozliwosci uzycia trybu pelnoekranowego na MAC OS. Z tego powodu wejscie do tego trybu powoduje ze zeby z niego wyjsc trzeba terminowac program z terminala.</p>
