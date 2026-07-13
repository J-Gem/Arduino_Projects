#define WARTEZEIT 20
int GruppeA = 8;   // LED 4
int GruppeB = 9;   // LED 1 + 7
int GruppeC = 10;  // LED 3 + 5
int GruppeD = 11;  // LED 2 + 6
int tasterPin = 13; // Taster an Pin 13

void zeigeAugen(int wert){
  // Lösche aller Gruppen
  digitalWrite(GruppeA, LOW);
  digitalWrite(GruppeB, LOW);
  digitalWrite(GruppeC, LOW);
  digitalWrite(GruppeD, LOW);
  // Ansteuerung aller Gruppen
  if(wert%2 != 0) // Ist der Wert ungerade?
    digitalWrite(GruppeA, HIGH);
  if(wert > 1)
    digitalWrite(GruppeB, HIGH);
  if(wert > 3)
    digitalWrite(GruppeC, HIGH);
  if(wert == 6)
    digitalWrite(GruppeD, HIGH);
  delay(WARTEZEIT); // Eine kurze Pause einfügen
}

void setup(){
  pinMode(GruppeA, OUTPUT);
  pinMode(GruppeB, OUTPUT);
  pinMode(GruppeC, OUTPUT);
  pinMode(GruppeD, OUTPUT);
}

void loop(){
  if(digitalRead(tasterPin) == HIGH)
  zeigeAugen(random(1, 7));  // Eine Zahl zwischen 1 und 6 generieren
}