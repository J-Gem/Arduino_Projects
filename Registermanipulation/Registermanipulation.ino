byte pattern = 0;
void setup()
{
  DDRB = (1 << DDB0);
  PORTB = (1 << PORTB0);
  //pinMode(8, OUTPUT);
  //digitalWrite(8, HIGH);
}

void loop()   {
  //PORTB = pattern++;
  delay(100);
}

