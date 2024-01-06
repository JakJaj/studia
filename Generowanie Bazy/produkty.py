from random import randint
from random import uniform
warzywa = ["pomidory", "papryka", "cukinia", "ogorek", "baklazan", "ziemniaki", "marchew", "seler", "rzodkiewka", "sałata", "rzepa", "kalafior", "brokuł", "kapusta", "groszek", "fasola", "soczewica", "pomidory cherry", "pietruszka", "koper", "szpinak", "rukola", "szparagi", "cebula", "czosnek", "dynia", "burak", "jarmuz", "kalarepa", "bob", "groszek ptysiowy", "karczochy", "kukurydza", "szczypiorek", "pasternak", "por", "lubczyk", "kabaczek"]
owoce = ["jablka", "gruszki", "sliwki", "wisnie", "brzoskwinie", "morele", "nektarynki", "pomarancze", "cytryny", "limonki", "grejpfruty", "banany", "winogrona", "truskawki", "maliny", "borowki", "jagody", "porzeczki", "agrest", "arbuz", "melon", "mango", "ananas", "kiwi", "papaja", "liczi", "daktyle", "figi", "rodzynki", "granat"]
mięsa = ["wolowina", "czerwona wieprzowina", "biala wieprzowina", "drob", "kurczak", "indyk", "kaczka", "ges", "cielecina", "baranina", "dziczyzna", "jagniecina", "kurczak grillowany", "wieprzowina wedzona", "kielbasa"]
nabiał = ["mleko", "jogurt", "kefir", "twarog", "ser feta", "ser camembert", "ser gouda", "ser cheddar", "ser mozzarella", "jajka", "mascarpone", "smietana", "maslanka", "maslo"]
pieczywo = ["chleb pszenny", "chleb razowy", "chleb z ziarnami", "bulki", "chleb ciemny", "chleb na zakwasie", "chleb tostowy", "baguette", "ciabatta", "chleb pita"]
słodycze = ["czekolada", "lody", "cukierki", "guma do zucia", "zelki", "batoniki", "ciastka", "lizaki", "platki kukurydziane z miodem", "krowki","czekolada biala","czekolada deserowa","czekolada z orzechami","pianki","ciastka maślane","biszkopty"]
konserwy = ["konserwy rybne", "konserwy miesne", "konserwy warzywne", "konserwy zup", "konserwy z fasoli", "konserwy z ciecierzycy", "konserwy z soczewicy", "konserwy z kukurydzy", "konserwy z kapusty", "konserwy z ogorków", "konserwy z pomidorow", "konserwy z miesem mielonym", "konserwy z miesem drobiowym", "konserwy z miesem wołowym", "konserwy z miesem wieprzowym", "konserwy z mięsem jagniecym", "konserwy z miesem baranim", "konserwy z miesem z dziczyzny" ]
mrożonki = ["mrozone ziemniaki", "mrozone frytki", "mrozone pierogi", "mrozone krokiety", "mrozone kluski", "mrozone pierogi z mięsem", "mrozone pierogi z serem", "mrozone krewetki", "mrozone kalmary", "mrozone klopsiki", "mrozone kotlety", "mrozone mieso mielone", "mrozone mieso drobiowe", "mrozone mieso wolowe", "mrozone mieso wieprzowe"]
nasiona_orzechy = ["slonecznik", "pestki dyni", "orzechy wloskie", "orzechy laskowe", "orzechy ziemne", "migdaly", "orzechy brazylijskie", "orzechy nerkowca", "pistacje", "orzechy makadamia", "orzechy pekan", "pestki slonecznika", "sezam", "nasiona chia", "nasiona lnu", "nasiona konopi", "nasiona szalwii", "nasiona dyni", "nasiona sezamu", "nasiona kozieradki"]
ryby = ["losos", "dorsz", "halibut", "tunczyk", "pstrag", "makrela", "sardynki", "szprot", "fladra", "sola", "karp", "węgorz", "okon", "szczupak", "pomidor", "mintaj", "sledz", "storozec", "dorsz wędzony"]
napoje = ["woda", "sok pomaranczowy", "sok jabłkowy", "cola", "fanta", "sprite", "herbata", "kawa", "piwo", "wino", "whisky", "vodka", "gin", "rum", "sok z malin", "sok z truskawek", "sok z czarnej porzeczki", "sok z granatu", "sok z grejpfruta", "sok z arbuza", "sok z jablka i marchwi", "kawa rozpuszczalna", "kawa zbozowa", "napoj sojowy", "napoj ryzowy", "herbata ziolowa", "herbata owocowa", "napoj z kokosa", "napoj z mleka kokosowego"]
produkty_zbozowe = ["maka pszenna", "maka zytnia", "maka orkiszowa", "maka gryczana", "kasza jaglana", "kasza gryczana", "kasza manna", "kasza jeczmienna", "kasza peczak", "kasza bulgur", "platki owsiane", "platki jaglane", "platki kukurydziane", "platki gryczane", "ryz", "kuskus", "makaron", "makaron razowy", "makaron z soi", "makaron z kaszy jaglanej", "maka kukurydziana"]
przyprawy = ["pieprz", "sol", "cukier", "curry", "kumin", "kurkuma", "szafran", "oregano", "tymianek", "bazylia", "natka pietruszki", "kolendra", "gozdziki", "ziele angielskie", "liscie laurowe", "czarny pieprz", "imbir", "majeranek", "galka muszkatołowa", "papryka ostra", "papryka slodka", "kardamon", "cynamon", "anyz", "musztarda", "ziola prowansalskie", "pesto", "salsa", "keczup", "majonez" ]
tłuszcze = ["olej rzepakowy", "olej slonecznikowy", "olej lniany", "olej z awokado", "smalec", "margaryna", "olej kokosowy", "olej z orzechów wloskich", "olej z pestek winogron"]


ceny = [round(uniform(10, 25),2) for i in range(1000)]

for i in range(len(nabiał)):
  print(f"INSERT INTO produkty values({i+1},'{nabiał[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 1);")

ceny = [round(uniform(30, 100),2) for i in range(1000)]
for i in range(len(mięsa)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał)},'{mięsa[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 2);")

ceny = [round(uniform(1, 15),2) for i in range(1000)]
for i in range(len(owoce)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa)},'{owoce[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 3);")

ceny = [round(uniform(5, 20),2) for i in range(1000)]
for i in range(len(warzywa)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce)},'{warzywa[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 4);")

ceny = [round(uniform(2, 20),2) for i in range(1000)]
for i in range(len(pieczywo)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa)} ,'{pieczywo[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 5);")

ceny = [round(uniform(1, 10),2) for i in range(1000)]
for i in range(len(słodycze)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo)} ,'{słodycze[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 6);")

ceny = [round(uniform(2, 10),2) for i in range(1000)]
for i in range(len(napoje)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze)} ,'{napoje[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 7);")

ceny = [round(uniform(8, 20),2) for i in range(1000)]
for i in range(len(produkty_zbozowe)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje)} ,'{produkty_zbozowe[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 8);")
  
ceny = [round(uniform(1, 10),2) for i in range(1000)]
for i in range(len(przyprawy)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje) + len(produkty_zbozowe)} ,'{przyprawy[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 9);")

ceny = [round(uniform(10, 30),2) for i in range(1000)]
for i in range(len(tłuszcze)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje) + len(produkty_zbozowe) + len(przyprawy)} ,'{tłuszcze[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 10);")

ceny = [round(uniform(30, 130),2) for i in range(1000)]
for i in range(len(ryby)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje) + len(produkty_zbozowe) + len(przyprawy) + len(tłuszcze)} ,'{ryby[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 11);")

ceny = [round(uniform(5, 30),2) for i in range(1000)]
for i in range(len(konserwy)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje) + len(produkty_zbozowe) + len(przyprawy) + len(tłuszcze) + len(ryby)} ,'{konserwy[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 12);")

ceny = [round(uniform(5, 30),2) for i in range(1000)]
for i in range(len(mrożonki)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje) + len(produkty_zbozowe) + len(przyprawy) + len(tłuszcze) + len(ryby) + len(konserwy)} ,'{mrożonki[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 13);")

ceny = [round(uniform(7, 18),2) for i in range(1000)]
for i in range(len(nasiona_orzechy)):
  print(f"INSERT INTO produkty values({i+1 + len(nabiał) + len(mięsa) + len(owoce) + len(warzywa) + len(pieczywo) + len(słodycze) + len(napoje) + len(produkty_zbozowe) + len(przyprawy) + len(tłuszcze) + len(ryby) + len(mrożonki)} ,'{nasiona_orzechy[i]}',{ceny[randint(0,len(ceny) - 1)]}, 0, 14);")