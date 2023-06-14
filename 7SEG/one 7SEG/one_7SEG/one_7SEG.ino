int dataPin = 11,latchPin = 8, clockPin = 12;
const int SEG[10]{
  0b11000000, //0(g->a)
  0b11111001,
  0b10100100,
  0b10110000,
  0b10011001,
  0b10010010,
  0b10000010,
  0b11111000,
  0b10000000,
  0b10010000
};

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;i<10;i++){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,SEG[i]);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  }
}
