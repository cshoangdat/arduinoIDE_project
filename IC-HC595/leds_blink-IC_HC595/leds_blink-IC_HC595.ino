int dataPin = 5, latchPin = 6, clockPin = 7;
byte ledStatus;
void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}
void shiftOutHC595(int dataPin,int clockPin, byte ledStatus){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,ledStatus);
  digitalWrite(latchPin,HIGH);
}
void shiftOutHC595LSB(int dataPin,int clockPin, byte ledStatus){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,ledStatus);
  digitalWrite(latchPin,HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
  ledStatus = 0;
  for(int i = 0;i<8;i++){
    ledStatus = (ledStatus<<1)|1;
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(100);
  }
  for(int i = 0;i<8;i++){
    ledStatus = (ledStatus<<1);
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(100);
  }
  for(int i = 0;i<20;i++){
    ledStatus = 0b11111111;
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(50);
    ledStatus = 0b00000000;
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(50);
  }
  for(int i = 0;i<8;i++){
    ledStatus = (ledStatus<<2)|2;
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(100);
  }
  for(int i = 0;i<8;i++){
    ledStatus = (ledStatus<<2)|3;
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(100);
  }
  for(int i = 0;i<8;i++){
    ledStatus = (ledStatus<<2)|2;
    shiftOutHC595LSB(dataPin,clockPin,ledStatus);
    delay(100);
  }
  for(int i = 0;i<8;i++){
    ledStatus = (ledStatus<<2);
    shiftOutHC595LSB(dataPin,clockPin,ledStatus);
    delay(100);
  }
}
