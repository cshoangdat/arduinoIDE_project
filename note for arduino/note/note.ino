Nhập xuất Digital (Digital I/O):
- pinMode(chân điều khiển, mode); (mode: INPUT, INPUT_PULLUP, OUTPUT);
- digitalWrite(chân điều khiển, value); (value: HIGH, LOW) -> HIGH: xuất tín hiệu ở điện thế 5V hoặc 3.3 V , LOW: điện thế mức 0;
- digitalRead (chân điều khiển); -> đọc tín hiệu điện từ chân digital (HIGH hoặc LOW)
Nhập xuất Analog (Analog I/O):
- analogReference(type) -> đặt lại mức điện áp tối đa của tín hiệu; (type: DEFAULT(đặt mức tối đa là 5 hoặc 3.3 V theo nguồn; //INTERNAL: đặt lại mức điện áp tối đa là 1.1 hoặc 2.56 
INTERNAL1V1 :ĐẶT LẠI MỨC ĐIỆN ÁP TỐI ĐA LÀ 1.1V, INTERNAL2V56 : ĐẶT LẠI MỨC ĐIỆN ÁP TỐI ĐA LÀ 2.56 V)// -> CHỈ SỬ DỤNG TRÊN ARDUINO MEGA
EXTERNAL : ĐẶT LẠI MỨC ĐIỆN ÁP TỐI ĐA BẰNG VỚI MỨC ĐIỆN ÁP ĐƯỢC CẤP VÀO CHÂN AREF(0-5V)
- analogRead(chân đọc điện áp) ->  đọc giá trị điện áp từ 1 chân Analog (A0 - A5)
- analogWrite (chân phát xung PWM, giá trị xung PWM) giá trị xung từ 0 đến 255 


void setup() {
 pinMode();
 Serial.begin(speed) -> khởi động 1 cổng baud cho trước có trên arduino để giao tiếp với máy tính
 mức baud: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, hoặc 115200
 để xuất thông tin từ arduino ra màn hình máy tính = crlt + shift + M
 hàm được sd hiện thị văn bản trên màn hình mt từ arduino là Serial.print
}

void loop() {
  // put your main code here, to run repeatedly:

}
