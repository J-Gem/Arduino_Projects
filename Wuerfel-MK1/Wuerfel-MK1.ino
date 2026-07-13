#define WARTEZEIT 20
int augen[6][7] = {{0, 0, 0, 1, 0, 0, 0},    // Würfelzahl 1
                   {1, 0, 0, 0, 0, 0, 1},    // Würfelzahl 2
                   {1, 0, 0, 1, 0, 0, 1},    // Würfelzahl 3
                   {1, 0, 1, 0, 1, 0, 1},    // Würfelzahl 4
                   {1, 0, 1, 1, 1, 0, 1},    // Würfelzahl 5
                   {1, 1, 1, 0, 1, 1, 1}};   // Würfelzahl 6

int pin[] = {2, 3, 4, 5, 6, 7, 8};
int pinOffset = 2;  // Erste LED ist auf PIN 2
int tasterPin = 13; // Taster an Pin 13

void zeigeAugen(int wert){
  for(int i = 0; i < 7; i++)
    digitalWrite(i + pinOffset, (augen[wert - 1][i] == 1)?HIGH:LOW);
  delay(WARTEZEIT);  // Eine kurze Pause einfügen
}

void setup(){
  for(int i = 0; i < 7; i++)
    pinMode(pin[i], OUTPUT);
  pinMode(tasterPin, INPUT);
}

void loop(){
  if(digitalRead(tasterPin) == HIGH)
  zeigeAugen(random(1, 7));  // Eine Zahl zwischen 1 und 6 generieren
}