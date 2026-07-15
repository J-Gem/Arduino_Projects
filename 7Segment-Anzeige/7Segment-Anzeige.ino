#include "SevSeg.h"
SevSeg sevseg;  // sieben Segment Objekt initialisieren
void setup(){
  byte numDigits = 4;  // Anzahl der Ziffern
  byte digitPins[] = {2, 3, 4, 5}; // Die Pins zu den Ziffern werden festgelegt
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};  // Pins zu den Segmenten
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

}

void loop(){
  sevseg.setNumber(1234,3);  // Gewünschte Zahl eintragen

  sevseg.refreshDisplay();  // Nummer auf dem Display anzeigen
  sevseg.setBrightness(90); // Helligkeit des Displays in %
}