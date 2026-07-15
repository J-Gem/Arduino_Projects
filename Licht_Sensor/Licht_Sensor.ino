int pin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // Pin-Array
int analogPin = A0; // Pin des analogen Eingangs

// Funktion zur Steuerung der LEDs
void steuereLEDs(int wert){
  int bargraphWert = map(wert, 0, 1023, 0, 9);
  for(int i = 0; i < 10; i++)
    digitalWrite(pin[i], (bargraphWert >= i)?HIGH:LOW);
}

void setup(){
  for(int i = 0; i < 10; i++)
    pinMode(pin[i], OUTPUT);  // Alle Pins Ausgänge
}

void loop(){
  steuereLEDs(analogRead(analogPin));
}