const int trig = 7;
const int echo = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long duration ;
  int distance;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (int)(duration/58.824);
  Serial.print(distance);
  Serial.println("cm");
  delay(200);
}
