int count = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(5,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(5);
  if(button == 0){
    delay(500);
    if(button == 0)
    count++;
  }
  if(count == 1){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  if(count == 2){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  if(count == 3){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }
  if(count == 4){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
  }
  if(count == 5){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  if(count > 5){
    count = 1;
  }
}
