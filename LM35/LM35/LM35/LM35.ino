void setup() {
 Serial.begin(9600);
}
 
void loop() {
 int LM35 = analogRead(A0);
 float temp = (float)500*LM35/1023;
 Serial.print("nhiet do: ");
 Serial.println(temp,2);
 Serial.println();
 delay(500);
}
