#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Adafruit_MotorShield.h>
#include <SoftwareSerial.h>

const int buzzer = 14;
const int buzzer2 = 17;
const int dioda1 = 15;
const int dioda2 = 16;
const int trigger = 13;
const int echo = 2;
const int odleglosc3 = 45;
const int odleglosc2 = 30;
const int odleglosc1 = 10;
int flaga = 0;
//Inicjalizacja silnikow
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
//Inicjalizacja Bluetooth
SoftwareSerial BTserial(1, 0); // RX | TX
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(dioda1, OUTPUT);
  pinMode(dioda2, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  AFMS.begin();  
  BTserial.begin(9600);
  Dabble.begin(9600, 0, 1);   //Polaczenie z aplikacja
}

void loop()
{
  long czas, dystans;                 //Inicjalizacja czujnika odleglosci
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  czas = pulseIn(echo, HIGH);
  dystans = (czas/2) / 29.1;
  
  if (dystans < odleglosc1)   {                               //Sprawdzanie odleglosci od sciany dla 3 roznych odleglosci
    digitalWrite(buzzer2,HIGH);
  }else if (dystans >= odleglosc1 && dystans < odleglosc2) {
    digitalWrite(buzzer2,HIGH);
    delay(50);
    digitalWrite(buzzer2,LOW);
    delay(50);
  }else if (dystans >= odleglosc2 && dystans < odleglosc3) {
    digitalWrite(buzzer2,HIGH);
    delay(95);
    digitalWrite(buzzer2,LOW);
    delay(95);
  } 
  else {
    noTone(buzzer2);
  }
  Dabble.processInput();              //Nadaje predkosc silnikom w zaleznosci od wcisnietego przycisku
    if (GamePad.isUpPressed())
  {
    leftMotor->run(FORWARD); 
    leftMotor->setSpeed(100); 
    rightMotor->run(FORWARD);  
    rightMotor->setSpeed(100); 
  }
  else if (GamePad.isDownPressed())
  {
    leftMotor->setSpeed(100); 
    leftMotor->run(BACKWARD); 
    rightMotor->setSpeed(100); 
    rightMotor->run(BACKWARD);
  }
  
  else if (GamePad.isLeftPressed())
  {
    leftMotor->setSpeed(100); 
    leftMotor->run(BACKWARD); 
    rightMotor->setSpeed(100); 
    rightMotor->run(FORWARD); 
  }
  else if (GamePad.isRightPressed())
  {
    leftMotor->setSpeed(100); 
    leftMotor->run(FORWARD);  
    rightMotor->setSpeed(100); 
    rightMotor->run(BACKWARD); 
  }
  else{                                   //Zatrzymuje silniki gdy zaden przycisk nie jest nacisniety
    leftMotor->run(RELEASE);
    rightMotor->run(RELEASE);
  }
  if (GamePad.isTrianglePressed()){  //Syrena + diody
    delay(2000); 
    if (flaga == 1) {
      flaga =  0;
    }
    else{
      flaga = 1;
    }
  }
  if (flaga == 1){
    for (int i = 0; i < 5; i++) {
      digitalWrite(dioda1, HIGH); 
      digitalWrite(dioda2, LOW); 
      tone(buzzer, 440, 250); 
      delay(200); 
      digitalWrite(dioda1, LOW); 
      digitalWrite(dioda2, HIGH); 
      delay(200); 
      digitalWrite(dioda1, HIGH); 
      digitalWrite(dioda2, LOW); 
      tone(buzzer, 660, 250); 
      delay(200); 
      digitalWrite(dioda1, LOW); 
      digitalWrite(dioda2, HIGH); 
      delay(200); 
    }
  }
    else{
      noTone(buzzer); 
      digitalWrite(dioda1, LOW);
      digitalWrite(dioda2, LOW);
    }
  if (GamePad.isCrossPressed()){      //Diody policyjne
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
    digitalWrite(dioda1, HIGH); 
    digitalWrite(dioda2, LOW);
    delay(200);
    digitalWrite(dioda1, LOW); 
    digitalWrite(dioda2, HIGH); 
    delay(200); 
      }
      delay(500);
    }
  }
  if (GamePad.isCirclePressed()){     //Syrena
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
    tone(buzzer, 440, 250); 
    delay(200); 
    tone(buzzer, 660, 250); 
    delay(200); 
      }
      delay(500);
    }
  }
}


