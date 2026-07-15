int analogWertPin0;
int analogWertPin1;

void setup(){
  Serial.begin(9600);
}

void loop(){
  analogWertPin0 = analogRead(A0);
  analogWertPin1 = analogRead(A1);
  int messwert = analogWertPin1 - analogWertPin0;
  // Messwert an die serielle Schnittstelle schicken
  Serial.println(messwert);
  delay(50);  // Eine kurze Pause
}