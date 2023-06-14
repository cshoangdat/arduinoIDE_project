#include <PS2X_lib.h>
#define PS2_DAT 13
#define PS2_CMD 12
#define PS2_SEL 10
#define PS2_CLK 11
#define pressures false
#define rumble false
PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;
int A;
#define IN3_1 2
#define IN4_1 3
#define IN3_2 4
#define IN4_2 5
#define IN3_3 6
#define IN4_3 7
#define IN3_4 9
#define IN4_4 8
void setup() {
  // put your setup code here, to run once:
  pinMode(IN3_1, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN3_3, OUTPUT);
  pinMode(IN3_4, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  pinMode(IN4_3, OUTPUT);
  pinMode(IN4_4, OUTPUT);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN3_3, LOW);
  digitalWrite(IN3_4, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN4_2, LOW);
  digitalWrite(IN4_3, LOW);
  digitalWrite(IN4_4, LOW);
  Serial.begin(57600);
  delay(300);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
}
void backward() {
      digitalWrite(IN3_1, HIGH);
      digitalWrite(IN4_1, LOW);
      digitalWrite(IN3_2, HIGH);
      digitalWrite(IN4_2, LOW);
      digitalWrite(IN3_3, HIGH);
      digitalWrite(IN4_3, LOW);
      digitalWrite(IN3_4, HIGH);
      digitalWrite(IN4_4, LOW);
}

void forward() {
      digitalWrite(IN3_1, LOW);
      digitalWrite(IN4_1, HIGH);
      digitalWrite(IN3_2, LOW);
      digitalWrite(IN4_2, HIGH);
      digitalWrite(IN3_3, LOW);
      digitalWrite(IN4_3, HIGH);
      digitalWrite(IN3_4, LOW);
      digitalWrite(IN4_4, HIGH);
}

void left() {
      digitalWrite(IN3_1, LOW);
      digitalWrite(IN4_1, HIGH);
      digitalWrite(IN3_2, HIGH);
      digitalWrite(IN4_2, LOW);
      digitalWrite(IN3_3, HIGH);
      digitalWrite(IN4_3, LOW);
      digitalWrite(IN3_4, LOW);
      digitalWrite(IN4_4, HIGH);
}

void right(){
      digitalWrite(IN3_1, HIGH);
      digitalWrite(IN4_1, LOW);
      digitalWrite(IN3_2, LOW);
      digitalWrite(IN4_2, HIGH);
      digitalWrite(IN3_3, LOW);
      digitalWrite(IN4_3, HIGH);
      digitalWrite(IN3_4, HIGH);
      digitalWrite(IN4_4, LOW);
}

void stop(){
      digitalWrite(IN3_1, LOW);
      digitalWrite(IN4_1, LOW);
      digitalWrite(IN3_2, LOW);
      digitalWrite(IN4_2, LOW);
      digitalWrite(IN3_3, LOW);
      digitalWrite(IN4_3, LOW);
      digitalWrite(IN3_4, LOW);
      digitalWrite(IN4_4, LOW);
}

void PS2_process(){
  ps2x.read_gamepad(false, vibrate);
  //tien
  if(ps2x.Button(PSB_PAD_UP)){
  Serial.println("len");
  A = 1;
  }
  //lui
  else if(ps2x.Button(PSB_PAD_DOWN))
  A = 2;
  else if(ps2x.Button(PSB_PAD_RIGHT))
  A = 3;
  else if(ps2x.Button(PSB_PAD_LEFT))
  A = 4;
  else
  A = 0;
  delay(50);
}
void loop() {
  // put your main code here, to run repeatedly:
  PS2_process();
  if(A == 1) forward();
  if(A == 2) backward();
  if(A == 3) right();
  if(A == 4) left();
  if(A == 0) stop();
  
}
