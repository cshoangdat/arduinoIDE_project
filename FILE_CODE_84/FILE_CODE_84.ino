#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11); // tx 10 rx 11
int _timeout;
String _buffer;
int tinhieu1 = 3;
int t=0;
/////////////////////////////////
String number1 = "0912XXXXX"; //-> thay so cua bạn vao day so 1

void setup() {
  delay(5000); //delay 5 giây
  Serial.begin(9600);
  pinMode(tinhieu1,INPUT);
  digitalWrite(tinhieu1,0);
  _buffer.reserve(50);
  Serial.println("Sistem Started...");
  sim.begin(9600);
  delay(1000);
}
void loop() {
  int gtth1 = digitalRead(tinhieu1); // DOC TRANG THAI th1
 Serial.println(gtth1);
 //////////////////////////
 if ((gtth1 == 0)&&(t==0))// nếu có th1 trả về
 { 
    callNumber1(); // chuong trinh con gọi điện 
    delay(12000);
    sim.print("ATH"); 
    sim.println(";"); 
    SendMessage1(); // chuong trinh con nhắn tin  
    delay(5000);       
    t=1;  
 }
 if (gtth1 == 1)// nếu có th1 trả về
 {
  t=0;
 }
}
////////////////////////////////
void SendMessage1()   // chuong trình con nhăn tin có BĐ level 1
{
  //Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  //Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number1 + "\"\r"); //Mobile phone number to send message
  delay(1000);
  String SMS = "Co vat can";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  _buffer = _readSerial();
 // loop();
}
///////////////////////////////
void callNumber1() {  // chuong trinh con gọi dien
  sim.print (F("ATD"));
  sim.print (number1);
  sim.print (F(";\r\n"));
  _buffer = _readSerial();
  Serial.println(_buffer);
}
String _readSerial() {
  _timeout = 0;
  while  (!sim.available() && _timeout < 10000  )
  {
    delay(13);
    _timeout++;
  }
  if (sim.available()) {
    return sim.readString();
  }
}
