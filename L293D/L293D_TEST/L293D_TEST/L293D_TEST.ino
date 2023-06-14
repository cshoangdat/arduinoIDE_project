#include <AFMotor.h>
AF_DCMotor motor4(4);
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600); //Mở cổng Serial
    motor4.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor4.run(FORWARD);
  delay(500);
  motor4.run(BACKWARD);
  delay(500);
  motor4.run(RELEASE);
  delay(500);
}
