byte ledPin[] = {8,9,10};
void setup() {
  // put your setup code here, to run once:
  for(int i =0; i< sizeof(ledPin);i++){
    pinMode(ledPin[i],OUTPUT);
    digitalWrite(ledPin[i],LOW);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int changeRes = analogRead(A0);
  Serial.println(changeRes);
  int voltage = map(changeRes,0,1023,0,5000);
  Serial.println(voltage);
  Serial.println();
  if(changeRes >0 && changeRes <=341){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  }
  if(changeRes >341 && changeRes <=682){
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }
  if(changeRes >682 && changeRes <=1023){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }
}
