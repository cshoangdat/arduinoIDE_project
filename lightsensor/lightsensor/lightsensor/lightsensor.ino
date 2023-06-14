int lightsensor = 7;
int led = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(lightsensor,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(lightsensor);
  Serial.println(value);
  digitalWrite(led,value);
}
