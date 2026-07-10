int taktPin = 8;   // SH_CP
int speicherPin = 9;  //  ST_CP
int datenPin = 10;   // DS

void sendeBytes(int wert){
  digitalWrite(speicherPin, LOW);
  shiftOut(datenPin, taktPin, MSBFIRST, wert >> 8);
  shiftOut(datenPin, taktPin, MSBFIRST, wert & 255);
  digitalWrite(speicherPin, HIGH);
}


void setup(){
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);
}

void loop(){
  sendeBytes(0B1010101001010101);  // übertragende Binärzahl = 26181(dez)
}

