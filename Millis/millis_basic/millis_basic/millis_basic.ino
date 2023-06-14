unsigned long time ;
unsigned long startTime;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  startTime = millis();
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Time: ");
  time = millis() - startTime;
  if(time >500){
    if(digitalRead(10) == LOW)
    digitalWrite(10,HIGH);
  else
    digitalWrite(10,LOW);
  startTime = millis();
  }
  Serial.println(time);
}
