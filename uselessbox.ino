
#include <Servo.h> //Die Bibliothek Servo wird ins Programm eingeführt

const int  buttonPin = 3; //Die Variable buttonPin wird deklariert und der Wert 2 zugewiesen

int buttonState = 0; //Die Variable buttonState wird deklariert und der Wert 0 zugewiesen

Servo myservo; //Deklaration des Objektes myservo aus der Klasse Servo

void setup() //Hier kommen alle Datendeklarationen und Methodenaufrufe für die Initialisierung hinein
{
  pinMode(4, OUTPUT); //Pin 4 wird als Ausgang definiert
  pinMode(2, OUTPUT); //Pin 2 wird als Ausgang definiert
  digitalWrite(4, HIGH); //Pin 4 wird auf High (ca 4,5V) gesetzt
  digitalWrite(2, LOW); //Pin 2 wird auf Low (GND) gesetzt
  pinMode(buttonPin, INPUT); // Pin D2 als Eingang gesetzt (an diesen Pin wird der Schalter angeschlossen)
  myservo.attach(9); //Servo Steuerleitung liegt an Pin D9
}

void loop() //Hier kommt alles rein was in der Endlosschleife gebraucht wird hinein
{
  buttonState = digitalRead(buttonPin); //Abfrage des logischen Spannungspegels an Pin D2
  if (buttonState == HIGH) { //Vergleich mit der Variable buttonState
       myservo.write(70); //Servo bewegt sich soweit bis der Schalter umgelegt wird
       delay(15); //Warte 15 Millisekunden
       myservo.write(0); //Servo kehrt zur Ausgangsposition zurück
  }
}
