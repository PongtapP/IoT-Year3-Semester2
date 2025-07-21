#include <WiFi.h>
#include <FirebaseESP32.h>
#include <SimpleDHT.h>

#define WIFI_SSID "MusketBears"
#define WIFI_PASSWORD "asd66180"

#define FIREBASE_HOST "https://iot-project-769c8-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ZxxbnzssXofV9mRPGAzqTpL1toXGeuuDp5vs2xZW"

#define DHT_PIN 15          // พินที่เชื่อมต่อกับเซ็นเซอร์ DHT22

FirebaseData firebaseData;
FirebaseConfig config;
FirebaseAuth auth;

SimpleDHT22 dht(DHT_PIN);  // สร้างอ็อบเจ็กต์สำหรับเซ็นเซอร์ DHT22

void setup() {
  Serial.begin(115200);
  
  // เชื่อมต่อ WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to WiFi");

  // ตั้งค่า Firebase
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
void loop() {
  // ตัวแปรเพื่อเก็บค่าอุณหภูมิและความชื้น
  byte temperature = 0;
  byte humidity = 0;

  // อ่านค่าจากเซ็นเซอร์ DHT22
  int readStatus = dht.read(&temperature, &humidity, NULL);
  if (readStatus != SimpleDHTErrSuccess) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // ส่งข้อมูลไปยัง Firebase
  if (Firebase.setInt(firebaseData, "/Temperature", temperature)) {
    Serial.printf("Temperature sent to Firebase: %d\n", temperature);
  } else {
    Serial.println("Failed to send Temperature: " + firebaseData.errorReason());
  }
  if (Firebase.setInt(firebaseData, "/Humidity", humidity)) {
    Serial.printf("Humidity sent to Firebase: %d\n", humidity);
  } else {
    Serial.println("Failed to send Humidity: " + firebaseData.errorReason());
  }
  delay(2000);  // หน่วงเวลา 2 วินาที
}
