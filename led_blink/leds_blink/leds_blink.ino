byte ledPin[] = {3,4,5,6,7,8,9,10};
byte pinCount;
void setup(){
  pinCount = sizeof(ledPin);
  for(int i= 0; i< pinCount;i++){
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i],LOW);
  }
}

void loop(){
  for(int i=0;i<pinCount;i++){
    digitalWrite(ledPin[i], HIGH);
    delay(500);
  }
  for(int i=0;i<pinCount;i++){
    digitalWrite(ledPin[i], LOW);
    delay(500);
  }
}
