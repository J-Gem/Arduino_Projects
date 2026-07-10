#define DELAY0 10000  // Pause 0, 10 Sekunden
#define DELAY1 1000   // PAUSE 1, 1 Sekunde
#define DELAY2 2000   // Pause 2, 2 Sekunden
#define DELAY3 3000   // Pause 3, 3 Sekunden

int ledPinRotAuto = 7;
int ledPinGelbAuto = 6;
int ledPinGruenAuto = 5;
int ledPinRotFuss = 3;
int ledPinGruenFuss = 2;
int tasterPinAmpel = 8;
int tasterAmpelWert = LOW;  // Variable für den Status des Ampeltasters
byte ampelwert;

void setzeLEDs(int ampelwert, int pause){
  digitalWrite(ledPinRotAuto, (ampelwert&1)== 1?HIGH:LOW);
  digitalWrite(ledPinGelbAuto, (ampelwert&2)== 2?HIGH:LOW);
  digitalWrite(ledPinGruenAuto, (ampelwert&4)== 4?HIGH:LOW);
  digitalWrite(ledPinRotFuss, (ampelwert&8)== 8?HIGH:LOW);
  digitalWrite(ledPinGruenFuss, (ampelwert&16)== 16?HIGH:LOW);
  delay(pause);
}

void ampelUmschaltung(){
  setzeLEDs(10, 2000);
  setzeLEDs(9, 1000);
  setzeLEDs(17, 10000);
  setzeLEDs(9, 1000);
  setzeLEDs(11, 2000);
  setzeLEDs(12, 0);
}

void setup(){
  pinMode(ledPinRotAuto, OUTPUT);  // Pin als Ausgang
  pinMode(ledPinGelbAuto, OUTPUT); // Pin als Ausgang
  pinMode(ledPinGruenAuto, OUTPUT); // Pin als Ausgang
  pinMode(ledPinRotFuss, OUTPUT);
  pinMode(ledPinGruenFuss, INPUT);
  digitalWrite(ledPinGruenAuto, HIGH);
  digitalWrite(ledPinRotFuss, HIGH);
}

void loop(){
  // Ampeltasterstatus in Variable einlesen
  tasterAmpelWert = digitalRead(tasterPinAmpel);
  // Wurde Taaster gedrückt, rufe Funktion auf
  if(tasterAmpelWert == HIGH)
    ampelUmschaltung();
}