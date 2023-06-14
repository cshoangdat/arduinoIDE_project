void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(2);
  Serial.println(button);
  if(button == LOW)
  digitalWrite(13, HIGH);
  else
  digitalWrite(13,LOW);
}
