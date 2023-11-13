#include <Servo.h>
#define red 2
#define yellow 3
#define green 4
#define lewy A0
#define prawy A1
Servo myservo;

int lewy_rezystor;
int prawy_rezystor;
int dozwolona_roznica = 130;
int kat = 0;
int V = 0;
int max_wartosc = 0;
int kat_startu = 0;
int i = 1;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  kat = firstRun();
  myservo.write(kat);
}

void loop() {
  while (bateryLevel()){
  lewy_rezystor = analogRead(lewy);
  prawy_rezystor = analogRead(prawy);

  Serial.println("Lewy: " );
  Serial.println(lewy_rezystor);
  Serial.println("Prawy: ");
  Serial.println(prawy_rezystor);
  
  if(prawy_rezystor > lewy_rezystor + dozwolona_roznica){ 
    Serial.println("Obrot w lewo!");
    kat = kat + 1;
    myservo.write(kat);
    if(kat < 0) kat = 0;
    } 
    else if(lewy_rezystor > prawy_rezystor + dozwolona_roznica) {
     Serial.println("Obrot w prawo!");
     kat = kat - 1;
     myservo.write(kat);
     if(kat > 130) kat = 130;
     } 
     else  { 
    Serial.println("Jest ok nie zmieniam pozycji!");
    }

  Serial.println(" ");
  Serial.println(kat);
  delay(50);
  }
}

bool bateryLevel(){
  V = analogRead(A4);

  if (V < 700) {
    digitalWrite(red,HIGH); 
    digitalWrite(yellow,LOW); 
    digitalWrite(green,LOW);
    return false;
    }
  else if (V >= 700 && V < 850){
    digitalWrite(red,LOW); 
    digitalWrite(yellow,HIGH); 
    digitalWrite(green,LOW);
    return true;
    }
  else if (V >= 850){
    digitalWrite(red,LOW); 
    digitalWrite(yellow,LOW); 
    digitalWrite(green,HIGH);
    return true;
    }
}

int firstRun(){
  while (kat >= 0){
    myservo.write(kat);
    lewy_rezystor = analogRead(A0); //pin sterujacy lewym rezystorem
    prawy_rezystor = analogRead(A1);
    if (lewy_rezystor + prawy_rezystor > max_wartosc){
      max_wartosc = lewy_rezystor + prawy_rezystor;
      kat_startu = kat;
    }
    if (kat == 130){
      i = -1;
    }
    kat += i;
    delay(25);
  }
  return kat_startu;
}

