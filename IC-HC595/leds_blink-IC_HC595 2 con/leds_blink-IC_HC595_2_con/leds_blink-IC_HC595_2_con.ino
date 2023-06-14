int dataPin = 5, latchPin = 6, clockPin = 7;
const int HC595_COUNT = 2;
byte ledStatus[HC595_COUNT] = {0};

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}

void shiftOutHC595(int dataPin, int clockPin,byte ledStatus[]){
  digitalWrite(latchPin,LOW);
  for(int i = 0;i<HC595_COUNT;i++){
  shiftOut(dataPin,clockPin,MSBFIRST,ledStatus[i]);
  }
  digitalWrite(latchPin,HIGH);
}
void shiftOutHC595LSB(int dataPin, int clockPin,byte ledStatus[]){
  digitalWrite(latchPin,LOW);
  for(int i = 0;i<HC595_COUNT;i++){
  shiftOut(dataPin,clockPin,LSBFIRST,ledStatus[i]);
  }
  digitalWrite(latchPin,HIGH);
}

void fillValuetoArr(byte value){
  for(int i =HC595_COUNT-1;i>=0;i--){
    ledStatus[i] = value;
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  fillValuetoArr(0);
  for(int i = HC595_COUNT-1;i>=0;i--){
   for(int j = 0;j<8;j++){
     ledStatus[i] = (ledStatus[i]<<1)|1;
     shiftOutHC595(dataPin,clockPin,ledStatus);
     delay(100);
   }
  }
  for(int i = HC595_COUNT-1;i>=0;i--){
   for(int j = 0;j<8;j++){
     ledStatus[i] = (ledStatus[i]<<1);
     shiftOutHC595(dataPin,clockPin,ledStatus);
     delay(100);
   }
  }
  for(int k =0;k<20;k++){
    fillValuetoArr(0b11111111);
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(50);
    fillValuetoArr(0b00000000);
    shiftOutHC595(dataPin,clockPin,ledStatus);
    delay(50);
  }
  for(int i = HC595_COUNT-1;i>=0;i--){
   for(int j = 0;j<8;j++){
     ledStatus[i] = (ledStatus[i]<<2)|2;
     shiftOutHC595(dataPin,clockPin,ledStatus);
     delay(100);
   }
  }
  for(int i = HC595_COUNT-1;i>=0;i--){
   for(int j = 0;j<8;j++){
     ledStatus[i] = (ledStatus[i]<<2)|3;
     shiftOutHC595(dataPin,clockPin,ledStatus);
     delay(100);
   }
  }
  for(int i = 0;i<HC595_COUNT;i++){
   for(int j = 0;j<8;j++){
     ledStatus[i] = (ledStatus[i]<<2)|2;
     shiftOutHC595LSB(dataPin,clockPin,ledStatus);
     delay(100);
   }
  }
  for(int i =0;i<HC595_COUNT;i++){
   for(int j = 0;j<8;j++){
     ledStatus[i] = (ledStatus[i]<<2);
     shiftOutHC595LSB(dataPin,clockPin,ledStatus);
     delay(100);
   }
  }
}
