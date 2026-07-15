import processing.serial.*;
Serial meinSeriellerPort;
int LDRMessung, xPos;

void setup(){
  size(321,250); smooth();
  println(Serial.list());
  meinSeriellerPort = new Serial(this, Serial.list()[0], 9600);
  meinSeriellerPort.bufferUntil('\n');
}

void draw(){
  background(0);
  zeichneRaster();
  stroke(255, 0, 0); strokeWeight(3);
  xPos = width / 2 + LDRMessung * 2;
  line(xPos, height / 2 - 10, xPos, height/ 2+10);
}

void zeichneRaster(){
  int h = 20;
  stroke(255, 255, 0); strokeWeight(1);
  line(0, height / 2, width, height /2);
  for(int i = 0; i <= width; i += 20){
    if(i == width / 2) h = 20;
    else h = 5;
    line(i, height / 2 - h, i, height / 2 + h);
  }
}

void serialEvent(Serial meinSeriellerPort) {
  String portStream = meinSeriellerPort.readString();
  float data = float(portStream);
  LDRMessung = (int)map(data, 0, 1023, 0, width);
}
