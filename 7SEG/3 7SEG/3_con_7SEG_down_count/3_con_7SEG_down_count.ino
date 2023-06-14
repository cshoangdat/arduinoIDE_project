//chân ST_CP của 74HC595
int latchPin = 6;
//chân SH_CP của 74HC595
int clockPin = 7;
//Chân DS của 74HC595
int dataPin = 5;
const byte Seg[10] = {
  0b11000000,//0
  0b11111001,//1
  0b10100100,//2
  0b10110000,//3
  0b10011001,//4
  0b10010010,//5
  0b10000010,//6
  0b11111000,//7
  0b10000000,//8
  0b10010000,//9
};
 
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
void SEG7display(unsigned long value, byte SEG7Count = 3) {
  
  byte *array = new byte[SEG7Count];
  for (byte i = 0; i < SEG7Count; i++) {
    //Lấy các chữ số từ phải quá trái
    array[i] = (byte)(value % 10UL);
    value = (unsigned long)(value /10UL);
  }
  digitalWrite(latchPin, LOW);
  for (int i = 0; i < SEG7Count; i++)
    shiftOut(dataPin, clockPin, MSBFIRST, Seg[array[i]]); 
  
  digitalWrite(latchPin, HIGH);
  free(array);
}
 
 
void loop() { 
  static unsigned long point = 999;  
  SEG7display(point, 3);
  point = (unsigned long)(point-1);
  delay(50);
}
