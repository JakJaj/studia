from random import randint
jobs = ['Kierownik hurtowni', 'Magazynier', 'Pracownik obsługi klienta', 'Specjalista ds. zakupow', 'Pracownik kompletowania zamowien', 'Kierowca-dostawca', 'Inzynier ds. utrzymania ruchu', 'Pracownik kontroli jakosci', 'Analityk danych magazynowych', 'Specjalista ds. logistyki', 'Kierownik dzialu logistyki', 'Pracownik obsługi magazynu', 'Koordynator dostaw', 'Specjalista ds. zarzadzania zapasami', 'Dyrektor operacyjny', 'Pracownik ds. rozladunku i zaladunku', 'Kierownik ds. transportu', 'Pracownik magazynowy', 'Specjalista ds. sprzedazy hurtowej', 'Kierownik dzialu handlowego'] 

min = [randint(2800,4000) for i in range(10)]
max = [randint(6000,10000) for i in range(10)]
for i in range(len(jobs)):
  print(f"INSERT INTO STANOWISKA values({i+1},'{jobs[i]}',{min[randint(0,len(min) - 1)]},{max[randint(0,len(max) - 1)]}")