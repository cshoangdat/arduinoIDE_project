const int RED_PIN = 8;
const int GREEN_PIN = 9;
const int BLUE_PIN = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
displayAllBasicColors();
showSpectrum();
}

void displayAllBasicColors(){
  //tat tat ca cac den
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
//  bat mau do
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  //  bat mau xanh la
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(500);
  //  bat mau xanh duong
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(500);
  //  bat mau vang = do + xanh la
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(500);
  //  bat mau xanh lam = xanh la + xanh duong
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(500);
  //  bat mau tim = do + xanh duong
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(500);
  //  bat mau trang = do + xanh duong + xanh la
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(500);
}
//hieu ung cau vong:
void showSpectrum(){
  for(int i = 0;i<768;i++){
    showRGB(i);
    delay(10);
  }
}
//chuyen dan cac mau cua con led rgb thanh 7 mau
// mình chia nó thành 3 khu
// đỏ - xanh lục
// xanh lục - xanh lam
// xanh lam - đỏ
 
// gồm có 4 mốc
// 0   = đỏ chét (đỏ 100%)
// 255 = xanh lục 100%
// 511 = xanh dương (100%)
// 767 = lại là đỏ chét
void showRGB(int color){
  int redPWM;
  int greenPWM;
  int bluePWM;
  if(color <= 255){
    redPWM =255-color;
    greenPWM = color;
    bluePWM = 0;
  }
  else if(color<=511){
    redPWM =0;
    greenPWM =255-(color-256);
    bluePWM = color - 256;
  }
  else{
    redPWM = color - 512;//tat r sang dan
    greenPWM = 0; tat
    bluePWM = 255-(color-512); //sang dan r tat
  }
  analogWrite(RED_PIN,redPWM);
  analogWrite(BLUE_PIN,bluePWM);
  analogWrite(GREEN_PIN,greenPWM);
}
