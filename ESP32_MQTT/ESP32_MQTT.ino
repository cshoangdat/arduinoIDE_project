#include <AdafruitIO.h> //thêm thư viện AdafruitIO.h
#define IO_USERNAME  "hoangdat" //Key được lấy từ io.ardafruit.com
#define IO_KEY       "aio_yqXm21x2lBsv7kdZhNqn7VFFjLP0"

#define WIFI_SSID "HOANG DAT" //tên wifi để ESP kết nối với wifi
#define WIFI_PASS "24072002" //pass wifi mà ESP kết nối tới

#include <AdafruitIO_WiFi.h> //khai báo thư viện AdafruitIO_WiFi.h để kết nối đến Server
AdafruitIO_WiFi io(IO_USERNAME,IO_KEY,WIFI_SSID,WIFI_PASS); //Kết nối đến Server

#define led 2 //sử dụng LED có sẵn trên ESP

AdafruitIO_Feed *Test = io.feed("Test"); //khai báo con trỏ Test để chứa dữ liệu lấy từ feed của server

void handleMessage(AdafruitIO_Data *data){ //đọc dữ liệu
  Serial.print("receive<- "); //Xuất ra màn hình trạng thái nút bấm mới đọc được
  if(data->toPinLevel() == HIGH)
  Serial.println("HIGH");
  else
  Serial.println("LOW");
  digitalWrite(led,data->toPinLevel());
  //bật tắt led tương ứng với nút nhấn
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT); //để led là OUTPUT
  Serial.begin(115200);// bắt đầu Serial với tốc độ baud 115200
  while(!Serial)
  Serial.print("Connecting to Adafruit IO");
  io.connect(); // kết nối với Adafruit IO
  Test->get(); //lấy dữ liệu từ feed
  Test->onMessage(handleMessage); //hàm đọc dữ liệu
}

void loop() {
  // put your main code here, to run repeatedly:
  io.run(); //gọi hàm run
}
