//chân ST_CP của 74HC595
int latchPin = 6;
//chân SH_CP của 74HC595
int clockPin = 7;
//Chân DS của 74HC595
int dataPin = 5;
int RED_LED = 8, YELLOW_LED = 9, GREEN_LED =10;
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
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}
 
void SEG7display(unsigned long value, byte SEG7Count = 2) {
  
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
  static long point;
  
  point = random(20,90);
  do{
  digitalWrite(RED_LED,HIGH);
  SEG7display(point, 2);
  point = (long)(point-1);
  delay(1000);
  } while (point >=0);
  delay(100);
  digitalWrite(RED_LED,LOW);
  delay(100);
  
  point = random(20,90);
  do{
  digitalWrite(GREEN_LED,HIGH);
  SEG7display(point, 2);
  point = (long)(point-1);
  delay(1000);
  } while (point >=0);
  delay(100);
  digitalWrite(GREEN_LED,LOW);
  delay(100);

  point = 3;
  do{
  digitalWrite(YELLOW_LED,HIGH);
  SEG7display(point, 2);
  point = (long)(point-1);
  delay(1000);
  } while (point >=0);
  delay(100);
  digitalWrite(YELLOW_LED,LOW);
  delay(100);  
}
