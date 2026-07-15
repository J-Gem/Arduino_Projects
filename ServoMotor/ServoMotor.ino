#include <Servo.h>

Servo meinServo;   // Servo-Objekt
int analogPin = 0; // Analoger Pin
int potentiometerWert; // Speichert den Potentiometerwert

void setup() {
  meinServo.attach(9);  // Objekt mit Pin 9 verbinden
  Serial.begin(9600);  // Serielle Schnittstelle initialisieren
}

void loop(){
  potentiometerWert = map(analogRead(analogPin), 0, 1023, 0, 179);
  Serial.println(potentiometerWert);  // Ausgabe des Wertes
  meinServo.write(potentiometerWert); // Servo ansteuern
  delay(20);                          // Eine kurze Pause
}