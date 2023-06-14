void setup(){
  Serial.begin(9600);
}

void loop(){
  int bientro = analogRead(A0);
  Serial.println(bientro);
  int voltage;
  voltage = map(bientro,0,1023,0,5000);
  Serial.println(voltage);
  Serial.println();
  delay(200);
}
