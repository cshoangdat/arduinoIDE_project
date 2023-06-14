byte flag1 = 0;
byte button1 = 9;
byte button2 = 8;
#define enA 10
#define in1 11
#define in2 12

void setup() {
  // put your setup code here, to run once:
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.begin (9600);
}

void left_to_right(){
  analogWrite(enA,200);
  digitalWrite(in1,HIGH);
  digitalWrite(in2, LOW);
}

void right_to_left(){
  analogWrite(enA,200);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
}

void loop() {
  //byte flag1, flag2;
  // put your main code here, to run repeatedly:
  //left_to_right();
  byte button1_state = digitalRead(button1);
  Serial.print("button1:");
  Serial.println(button1_state);
  byte button2_state = digitalRead(button2);
  Serial.print("button2:");
  Serial.println(button2_state);
  if(button1_state == 0)
    flag1 = 1;
  if(button2_state == 0)
    flag1 = 0;
  if(flag1 == 0){
  right_to_left();
  delay(1000);
  }
  //if(button1_state == 0)
  //flag2 = 0;
  if(flag1 == 1){
  left_to_right();
  delay(1000);
  }
  Serial.print("co:");
  Serial.println(flag1);
}
