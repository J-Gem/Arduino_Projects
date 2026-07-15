#include <Servo.h>
#define ServoPin 9
Servo meinServo;
int mittelPosition = 90;
int ergebnisMessung = 0;
int messungSample = 0;
int ansprechZeit = 100;
int anzahlMessungen = 10;
unsigned long zeitLetzeMessung = 0;

void setup(){
  meinServo.attach(ServoPin);
  Serial.begin(9600);
}

void loop(){
  int analogWertPin0 = analogRead(A0);
  int analogWertPin1 = analogRead(A1);
  if(millis() - zeitLetzeMessung > ansprechZeit){
    for(int i = 0; i < anzahlMessungen; i++){
      int messung = analogWertPin1 - analogWertPin0;
      messungSample = messungSample + messung;
    }
    ergebnisMessung = messungSample/ anzahlMessungen;
    meinServo.write(mittelPosition + ergebnisMessung);
    zeitLetzeMessung = millis();
    Serial.println(analogWertPin1 - analogWertPin0                                                            );
  }
  //Serial.println(analogRead(A0));
  //Serial.println(analogRead(A1));
  messungSample = 0;
}