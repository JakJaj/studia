<!DOCTYPE HTML>
<html lang="pl">
  <head>
    <meta charset="utf-8"/>
    <title>Dane logowania</title>
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
    height: 800px;
    position: relative;
    font-size: xx-large;
    
   }
   #navigate
   {
    float: left;
    width: 10%;
    height: 800px;
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
   #info
   {
    background-color: rgb(104, 55, 240);
    width: 400px;
    padding: 60px;
    color: white;
    position: absolute;
    top: 35%;
    left: 30%;
   }
   .link
   {
    color: white;
   }
    </style>
  </head>
  
  <body>
    <div id="container">
      <div id="logo">
        <h1>
          Najlepsze filmy moim zdaniem
        </h1>
        Dane podane przy logowaniu </br></br>

      </div>

      <div id="navigate">
        <br/>&nbspNawigacja:</br>
        &nbsp<a href="strona.php" class="link">Do listy</a><br/>
        &nbsp<a href="logowanie.php" class="link">Do logowania</a>
      </div>

      <div id="content">
        <div id="info">
          Twój login:<br/>
          
          <?php 
            $login = $_POST['login'];
            $haslo = $_POST['haslo'];
            echo $login;
            $myfile = fopen("dane.txt", "w");
            fwrite($myfile,"Login: ".$login."\n");
            fwrite($myfile,"Hasło: ".$haslo."\n");
            fclose($myfile);
          ?><br/>
          
          <br/>Twoje hasło:<br/> 
          
          <?php 
          echo $haslo;
          ?><br/>
        
      </div>
      </div>
      
      <div id=footer>
        <a class="link" href="#logo">Powrót na góre</a></br></br>
        --- Najlepsze filmy moim zdaniem &copy; ---
      </div>
    </div>
  </body>
</html>