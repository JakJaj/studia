<!DOCTYPE HTML>
<html lang="pl">
<head>
  <meta charset="utf-8"/>
  <title>Najlepsze filmy!</title>
  <meta name="description" content="Spis listy moich ulubionych filmów"/>
  <meta name="keywords" content="film, kino"/>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
   #container
   {
    width: 1500px;
    margin-left: auto;
    margin-right: auto;
    font-family: 'Helvetica';
   }
   #logo
   {
    background-color: rgb(41, 8, 83);
    color: white;
    text-align: center;
    padding: 20px;
    font-family: 'Helvetica';
    
   }
   #content
   {
    color: white;
    text-align: center;
    float: left;
    font-family: "Helvetica";
    background: rgb(54,9,121);
    background: linear-gradient(180deg, rgba(54,9,121,1) 0%, rgba(113,1,214,1) 100%);
    width: 90%;
    
   }
   #navigate
   {
    float: left;
    width: 10%;
    height: 3808px;
    text-indent: 36px;
    font-size: large;
    color: white;
    background: rgb(54,9,121);
    background: linear-gradient(0deg, rgba(54,9,121,1) 0%, rgba(113,1,214,1) 100%);
    font-family: "Helvetica";
    
   }
   #footer
   {
    clear: both;
    text-align: center;
    background-color: rgb(41, 8, 83);
    color: white;
    padding: 10px;
    font-family: "Helvetica";
   }
   .link
   {
    color: white;
   }
   .logowanie
   {
    margin-left: 12px;
    width: 120px;
    height: 30px;
    border: none;
    cursor: pointer;
   }
  </style>
</head>


<body>
  <div id="container">
    <div id="logo">
      <h1>
        Najlepsze filmy moim zdaniem
      </h1>
      Poniżej prezentuje liste filmów które uznaje za najlepsze z danej kategorii </br></br>

    </div>
    

    <div id="navigate">
      <br/>&nbspNawigacja</br>
      &nbsp<a class="link" href="#dramat">Dramat</br></a>
      &nbsp<a class="link" href="#komedia">Komedia</br></a>
      &nbsp<a class="link" href="#horror">Horror</br></a>
      &nbsp<a class="link" href="#thriller">Thriller</br></a>
      &nbsp<a class="link" href="#wojenny">Wojenny</br></a>
      &nbsp<a class="link" href="#animacja">Animacja</br></a>
      &nbsp<a class="link" href="#kryminal">Kryminał</br></a>
      &nbsp<a class="link" href="#scifi">Sci-Fi</br></a>
      &nbsp<a class="link" href="#akcja">Akcja</br></a>
      &nbsp<a class="link" href="#swiateczny">Świąteczny</br></a></br>
      <button class="logowanie" onclick="location.href='logowanie.php'">Zaloguj się!</button>
    </div>
    <div id="content">
      <h3 id="dramat">Dramat:</h3>
  
      <a href="https://www.filmweb.pl/film/Skazani+na+Shawshank-1994-1048" target="_blank" title="Zobacz na filmwebie" class="link">Shawshank Redemption (1994)</a> </br></br>
      Opis: </br>
      Adaptacja opowiadania Stephena Kinga. Niesłusznie skazany na dożywocie bankier, stara się przetrwać w brutalnym, więziennym świecie.</br>
      <video width="500" height="240" controls>
        <source src="video/shawshank.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>
      </br>
  
      <h3 id="komedia">Komedia:</h3>
  
      <a href="https://www.filmweb.pl/film/Forrest+Gump-1994-998" target="_blank" title="Zobacz na filmwebie" class="link">Forrest Gump (1994)</a> </br></br>
      Opis: </br>
      Historia życia Forresta, chłopca o niskim ilorazie inteligencji z niedowładem kończyn, który staje się miliarderem i bohaterem wojny w Wietnamie. </br>
      <video width="500" height="240" controls>
        <source src="video/forrest.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>

      <h3 id="horror">Horror:</h3>
  
      <a href="https://www.filmweb.pl/film/L%C5%9Bnienie-1980-1020" target="_blank" title="Zobacz na filmwebie" class="link">The Shining (1980)</a> </br></br>
      Opis: </br>
      Jack podejmuje pracę stróża odciętego od świata hotelu Overlook. Wkrótce idylla zamienia się w koszmar.</br>
      <video width="500" height="240" controls>
        <source src="video/shining.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>

      <h3 id="thriller">Thriller:</h3> 
   
      <a href="https://www.filmweb.pl/film/Podziemny+kr%C4%85g-1999-837" target="_blank" title="Zobacz na filmwebie" class="link">Fight Club (1999)</a> </br></br>
      Opis: </br>
      Cierpiący na bezsenność mężczyzna poznaje gardzącego konsumpcyjnym stylem życia Tylera Durdena, który jest jego zupełnym przeciwieństwem.</br>
      <video width="500" height="240" controls>
        <source src="video/fight_club.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>

      <h3 id="wojenny">Wojenny:</h3> 
  
      <a href="https://www.filmweb.pl/film/%C5%BBycie+jest+pi%C4%99kne-1997-208" target="_blank" title="Zobacz na filmwebie" class="link"> La vita è bella (1997)</a> </br></br>
      Opis: </br>
      Zamknięty w obozie koncentracyjnym wraz z synem Guido próbuje przekonać chłopca, że okrutna rzeczywistość jest jedynie formą zabawy dla dorosłych.</br>
      <video width="500" height="240" controls>
        <source src="video/zycie_jest_piekne.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>

      <h3 id="animacja">Animacja:</h3> 
  
      <a href="https://www.filmweb.pl/film/Odlot-2009-436704" target="_blank" title="Zobacz na filmwebie" class="link">UP! (2009)</a> </br></br>
      Opis: </br>
      70-letni Carl po śmierci żony zamienia swój dom w statek powietrzny i odlatuje do Ameryki Południowej, by spełnić swoje marzenie.</br> Przez przypadek zabiera ze sobą ośmioletniego skauta.</br>
      <video width="500" height="240" controls>
        <source src="video/up.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>
  
      <h3 id="kryminal">Kryminał:</h3> 
  
      <a href="https://www.filmweb.pl/film/Siedem-1995-702" target="_blank" title="Zobacz na filmwebie" class="link">Se7en (1995)</a> </br></br>
      Opis: </br>
      Dwóch policjantów stara się złapać seryjnego mordercę wybierającego swoje ofiary według specjalnego klucza - siedmiu grzechów głównych.</br>
      <video width="500" height="240" controls>
        <source src="video/seven.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>


      <h3 id="scifi">Sci-Fi:</h3> 
  
      <a href="https://www.filmweb.pl/film/Incepcja-2010-500891" target="_blank" title="Zobacz na filmwebie" class="link">Inception (2010)</a> </br></br>
      Opis: </br>
      Czasy, gdy technologia pozwala na wchodzenie w świat snów. Złodziej Cobb ma za zadanie wszczepić myśl do śpiącego umysłu.</br>
      <video width="500" height="240" controls>
        <source src="video/incepcja.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>

      <h3 id="akcja">Akcja:</h3> 
  
      <a href="https://www.filmweb.pl/film/Top+Gun%3A+Maverick-2022-602101" target="_blank" title="Zobacz na filmwebie" class="link">Top Gun: Maverick (2022)</a> </br></br>
      Opis: </br>
      Po ponad 20 latach służby w lotnictwie marynarki wojennej, Pete "Maverick" Mitchell zostaje wezwany do legendarnej szkoły Top Gun.</br> Ma wyszkolić nowe pokolenie pilotów do niezwykle trudnej misji.</br>
      <video width="500" height="240" controls>
        a<source src="video/top_gun.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>

      <h3 id="swiateczny">Świąteczny:</h3>
  
      <a href="https://www.filmweb.pl/film/Opowie%C5%9B%C4%87+wigilijna-2009-450904" target="_blank" title="Zobacz na filmwebie" class="link">A Cristmas Carol (2009)</a> </br></br>
      Opis: </br>
      Ebenezera Scrooge'a nawiedzają trzy duchy. Od tej pory starzec zaczyna nadrabiać to, co utracił, będąc złym człowiekiem, i stara się wrócić na dobrą drogę.</br>
      <video width="500" height="240" controls>
        <source src="video/christmas_carol.mp4" type="video/mp4">
        Nie mozna odtworzyć w tej przeglądarce.
      </video>
      </br></br>
    </div>

    <div id="footer">
      <a class="link" href="#logo">Powrót na góre</a></br></br>
      --- Najlepsze filmy moim zdaniem &copy; ---
      
    </div>
  </div>
</body>
      
</html>