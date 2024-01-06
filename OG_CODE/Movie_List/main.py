from random import randint

user_choice = "wrong input"
within_range = False
movie_table = []


def show_movie_list():
    index_count = 1
    for film in movie_table:
        print( "[" + str(index_count) + "]" + " " + film)
        index_count += 1
    print()


def add_movie_to_list():
    film_choice = input("Jaki film chcesz dodać? ")
    movie_table.append(film_choice)
    print(f"Dodano film: {movie_table[len(movie_table) - 1]} ")
    print()


def picking_action():
    user_choice = input("Co chciałbyś zrobić? ")
    print()

    if user_choice.isdigit() == False:
        print("Wpisz numer!")
        print()

    if user_choice.isdigit() == True:
        if int(user_choice) == 6:
            quit("Miłego dnia!")
        if int(user_choice) in range(1, 7):
            return int(user_choice)
        else:
            print("Wpisz numer dla jednej z podanych akcji")
            print()


def picking_random_movie():
    randmomized = randint(0,len(movie_table) - 1)
    print(f'Wylosowano: "{movie_table[randmomized]}"')
    print()


def delete_movie_from_list():
    delete_movie = int(input("Wprowadź indeks filmu który chcesz usunąć: "))
    delete_movie -= 1
    print()
    print(f'Usunąłeś: "{movie_table.pop(delete_movie)}" z listy filmów')
    print()


def save_movie_list_to_file():
    file = open("movie.txt", "w+")
    for movie in movie_table:
        file.write(movie + "\n")
    file.close()
    print("Lista filmów została zapisana!")
    print()


def load_movies_from_file():

    try:
        file = open("movie.txt", "r")
        print("Znaleziono już istniejącą liste filmów")
    except FileNotFoundError:
        file = open("movie.txt", "w+")
        print("Utworzono nową listę")

    print()
    for line in file.readlines():
        movie_table.append(line.strip())
        file.close()


load_movies_from_file()

while user_choice not in range(1, 7) or within_range == False:

    print("1. Wyświetl listę filmów")
    print("2. Dodaj film do listy")
    print("3. Wylosuj film")
    print("4. Usuń film z listy")
    print("5. Zapisz liste do pliku")
    print("6. Wyjdź")
    print()

    user_choice = picking_action()

    if user_choice == 1:
        show_movie_list()
    elif user_choice == 2:
        add_movie_to_list()
    elif user_choice == 3:
        picking_random_movie()
    elif user_choice == 4:
        delete_movie_from_list()
    elif user_choice == 5:
        save_movie_list_to_file()