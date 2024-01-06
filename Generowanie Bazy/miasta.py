cities = ["Warszawa", "Krakow", "Łodz", "Wroclaw", "Poznan", "Gdansk", "Szczecin", "Bydgoszcz", "Lublin", "Katowice", "Bialystok", "Gdynia", "Czestochowa", "Radom", "Sosnowiec", "Torun", "Kielce", "Rzeszow", "Gliwice", "Zabrze", "Olsztyn", "Bielsko-Biala", "Bytom", "Ruda Slaska", "Rybnik", "Tychy", "Dabrowa Gornicza", "Elblag", "Plock", "Opole", "Walbrzych", "Zielona Gora", "Legnica", "Gorzow Wielkopolski", "Grudziadz", "Slupsk", "Jaworzno", "Koszalin", "Jelenia Gora", "Zagan", "Nowy Sacz", "Tarnow", "Chorzow", "Inowroclaw", "Kalisz", "Pila", "Lubin", "Gniezno", "Stargard", "Przemysl", "Mielec", "Legionowo", "Chelm", "Zamosc", "Swidnica", "Jastrzebie-Zdroj", "Siedlce", "Belchatow", "Ostroleka", "Myslowice", "Elk", "Bedzin", "Tczew", "Kedzierzyn-Kozle", "Zory", "Glogow", "Tomaszow Mazowiecki", "Suwalki"]



for i in range(len(cities)):
  print(f"INSERT INTO LOKALIZACJA values({i+1},'{cities[i]}');")