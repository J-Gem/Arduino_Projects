void setup(){
  DDRB = 0b11100000;  // Pin 8, 9, 10, als INPUT. PIN 11, 12, 13 als OUTPUT
  PORTB = 0b11111000;  // Pin 11, 12, 13 auf HIGH-PEGEL setzen
  Serial.begin(9600); // Serielle Schnittstelle mit 9600 Baud vorbereiten
}

void loop(){
  // Binäre Ausgabe von Register PINB über
  // die serielle Schnittstelle
  Serial.println(PINB, BIN);
  Serial.println(digitalRead(8));
  delay(1000);  // Pause von 1 Sekunde
  
}