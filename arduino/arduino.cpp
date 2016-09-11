/*
le bouton poussoir est connecté au pin 2 pour un mode INPUT_PULLUP
la Led est connectée au pins 4 avec une résistance de 220Ω
*/
#include <Arduino.h>
#include <SoftwareSerial.h>


//déclaration des variables
SoftwareSerial BTserial(9,10); //RX,TX
char c;

int pinBouton, pinLed, sortie;
boolean etatAllumage;
void setup()
{
  //initialisation des variables
  
  Serial.begin(9600);
  BTserial.begin(9600);

  sortie = 5;
  pinBouton = 2;
  pinLed = 4;
  etatAllumage=0;
  //définition des modes
  pinMode(pinBouton, INPUT_PULLUP);
  pinMode(sortie, OUTPUT);
  pinMode(pinLed, OUTPUT);
}
void loop()
{
  Serial.print(etatAllumage);
  
  if (etatAllumage) //on teste si etatAllumage est à 1
  {
    digitalWrite(pinLed, HIGH);//on allume la LED
    digitalWrite(sortie, HIGH);
  }
  else //sinon
  {
    digitalWrite(pinLed, LOW); //on éteint la LED
    digitalWrite(sortie, LOW);
  }
  
  //lecture de l'état du bouton et stockage dans etatBouton
  boolean etatPinBouton = digitalRead(pinBouton);
  Serial.println(etatPinBouton);
  
  //bluetooth
  if(BTserial.available())
  c = BTserial.read();

  if(c =='1') {
    if (etatAllumage) //si etatAllumage à 1
    {
      etatAllumage=0; //on le passe à 0
      c='0';
    }
    else //sinon
    {
      etatAllumage=1; //on le passe à 1
      c='0';
    }
  }
  
  if (!etatPinBouton)//si bouton appuyé (donc le pin indique 0 car il est en mode INPUT_PULLUP)
  {
    if (etatAllumage) //si etatAllumage à 1
    {
      etatAllumage=0; //on le passe à 0
    }
    else //sinon
    {
      etatAllumage=1; //on le passe à 1
    }
  }
  delay(200);
}
