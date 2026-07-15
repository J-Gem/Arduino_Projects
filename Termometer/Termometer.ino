#include "SevSeg.h"
SevSeg sevseg;  // sieben Segment Objekt initialisieren

// Temperatur Sensor
int TMP36 = A0;  // Temperatur Sensor ist am Analogen Pin A0
int sensorwert;
int temperatur = 0;  // Temperaturwert
int t = 500; //abstand zwischen Zeitlichen Messungen
unsigned long zeit;  // Zeit Variable


void setup(){
  zeit = millis();
  Serial.begin(9600);
  byte numDigits = 4;  // Anzahl der Ziffern
  byte digitPins[] = {2, 3, 4, 5}; // Die Pins zu den Ziffern werden festgelegt
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};  // Pins zu den Segmenten
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

}

void loop(){
  sensorwert = analogRead(TMP36);  // Auslesen des Sensorswerts
  temperatur = map(sensorwert, 0, 410, -50, 150);  // Umwandeln des Sensorswertes
  if((millis() - zeit) > t){
    zeit = millis();
    Serial.println(temperatur);
  }
  sevseg.setNumber(temperatur);  // Gewünschte Zahl eintragen
  sevseg.refreshDisplay();  // Nummer auf dem Display anzeigen
  sevseg.setBrightness(90); // Helligkeit des Displays in %

}