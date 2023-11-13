from collections import Counter

from random import randint
daty = []
for i in range(1000):
    daty.append(f'{randint(1,30)}-{randint(1,12)}-{randint(2012,2022)}')

print(daty)

numery = []
for i in range(1000):
    numery.append(randint(400000000,999999999))

print(numery)

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
polskie_miasta = ["Warszawa", "Kraków", "Łódź", "Wrocław", "Poznań", "Gdańsk", "Szczecin", "Bydgoszcz", "Lublin", "Katowice", "Białystok", "Gdynia", "Częstochowa", "Radom", "Sosnowiec", "Toruń", "Kielce", "Rzeszów", "Gliwice", "Zabrze", "Olsztyn", "Bielsko-Biała", "Bytom", "Ruda Śląska", "Rybnik", "Tychy", "Dąbrowa Górnicza", "Elbląg", "Płock", "Opole", "Wałbrzych", "Zielona Góra", "Legnica", "Gorzów Wielkopolski", "Grudziądz", "Słupsk", "Jaworzno", "Koszalin", "Jelenia Góra", "Żagań", "Nowy Sącz", "Tarnów", "Chorzów", "Inowrocław", "Kalisz", "Piła", "Lubin", "Gniezno", "Stargard", "Przemyśl", "Mielec", "Legionowo", "Chełm", "Zamość", "Świdnica", "Jastrzębie-Zdrój", "Siedlce", "Bełchatów", "Ostrołęka", "Mysłowice", "Ełk", "Będzin", "Tczew", "Kędzierzyn-Koźle", "Żory", "Głogów", "Tomaszów Mazowiecki", "Suwałki"]

wszystko = warzywa + owoce + mięsa + nabiał + pieczywo + konserwy + mrożonki + nasiona_orzechy + ryby + napoje + produkty_zbozowe + przyprawy + tłuszcze + słodycze

c = Counter(polskie_miasta)

print(c)
print(len(wszystko))
ź
