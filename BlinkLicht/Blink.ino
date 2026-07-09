int ledPin = 13; // Variable mit Pin 13 deklarieren + initialisieren
int inputPin = 9;
int impulsdauer = 500;
int Periodendauer = 1500;
int restdauer = Periodendauer - impulsdauer;

void setup(){
  pinMode(ledPin, OUTPUT); // Digitaler Pin 13 als Ausgang
  pinMode(inputPin, INPUT);  // Pin als Eingabe konfigurieren
  digitalWrite(inputPin, HIGH);  // Aktivieren des internen Pullup-Widerstandes
}

void loop(){
  digitalWrite(ledPin, HIGH);
  delay(impulsdauer);
  digitalWrite(ledPin, LOW);
  delay(restdauer);
}

//test