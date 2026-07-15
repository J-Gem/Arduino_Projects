#include <Wuerfel.h>

Wuerfel meinWuerfel(8, 9, 10, 11);

void setup() {
  pinMode(12, INPUT); 
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(12) == HIGH){
   meinWuerfel.roll();
  }
}
