kategorie = ["Nabial", "Mieso", "Owoce", "Warzywa", "Pieczywo", "Slodycze", "Napoje", "Produkty zbozowe", "Przyprawy", "Tluszcze", "Ryby", "Konserwy", "Mrozonki", "Nasiona i orzechy"]

for i in range(len(kategorie)):
  print(f"INSERT INTO KATEGORIA values({i+1},'{kategorie[i]}')")