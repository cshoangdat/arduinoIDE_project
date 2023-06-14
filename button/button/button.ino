int button = 2;
void setup(){
  Serial.begin(9600);
  pinMode(button,INPUT);
}
void loop(){
  int buttonStatus = digitalRead(button);
  Serial.println(buttonStatus);
  delay(200);
}
