//This example shows how to read, store and update database using get, set, push and update functions.

#include <WiFi.h>
#include <FirebaseESP32.h>
#include <SimpleDHT.h>

#define WIFI_SSID "IoT Lab"
#define WIFI_PASSWORD "IoT@123456"

#define FIREBASE_HOST "dht11-7cae8-default-rtdb.firebaseio.com/"

/** The database secret is obsoleted, please use other authentication methods, 
 * see examples in the Authentications folder. 
*/
#define FIREBASE_AUTH "7dRfnYJd39esRdGAy8JrPJ34HXfAvgix5AW0Xc4G"

//Define FirebaseESP32 data object
FirebaseData fbdo;
int i;
#define LED_01 2
#define LED_02 5
#define LED_03 18
#define LED_04 19

int pinDHT11 = 4;
SimpleDHT11 dht11;

byte temperature = 0;
byte humidity = 0;

void setup()
{
  pinMode(LED_01, OUTPUT); 
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);
  pinMode(LED_04, OUTPUT);
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(fbdo, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(fbdo, "tiny");
}
void loop()
{
  readDHT11();
  if(Firebase.setDouble(fbdo, "/TT_IoT/nhietdo",temperature))  
    Serial.println("Upload success");  
  else
    Serial.println("Upload fail");
    
    if(Firebase.setDouble(fbdo, "/TT_IoT/doam",humidity))  
    Serial.println("Upload success");  
  else
    Serial.println("Upload fail");  
  
 if(Firebase.getString(fbdo, "/TT_IoT/BULB_01"))
  {
    Serial.println("Download success: " + String(fbdo.stringData()));
    if(fbdo.stringData() == "ON")
      digitalWrite(LED_01, HIGH);
    else
      digitalWrite(LED_01, LOW);   
  }else {
    Serial.println("Download fail: " + String(fbdo.stringData())); 
  }

   if(Firebase.getString(fbdo, "/TT_IoT/BULB_02"))
  {
    Serial.println("Download success: " + String(fbdo.stringData()));
    if(fbdo.stringData() == "ON")
      digitalWrite(LED_02, HIGH);
    else
      digitalWrite(LED_02, LOW);   
  }else {
    Serial.println("Download fail: " + String(fbdo.stringData())); 
  }

   if(Firebase.getString(fbdo, "/TT_IoT/BULB_03"))
  {
    Serial.println("Download success: " + String(fbdo.stringData()));
    if(fbdo.stringData() == "ON")
      digitalWrite(LED_03, HIGH);
    else
      digitalWrite(LED_03, LOW);   
  }else {
    Serial.println("Download fail: " + String(fbdo.stringData())); 
  }

   if(Firebase.getString(fbdo, "/TT_IoT/BULB_04"))
  {
    Serial.println("Download success: " + String(fbdo.stringData()));
    if(fbdo.stringData() == "ON")
      digitalWrite(LED_04, HIGH);
    else
      digitalWrite(LED_04, LOW);   
  }else {
    Serial.println("Download fail: " + String(fbdo.stringData())); 
  }
  delay(3000);
}


void readDHT11()
{
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
  }
  else
  {
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" %");  
  }  
}
