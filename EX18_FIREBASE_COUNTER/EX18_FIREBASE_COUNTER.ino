#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "MusketBears"
#define WIFI_PASSWORD "asd66180"

#define FIREBASE_HOST "https://iot-project-769c8-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ZxxbnzssXofV9mRPGAzqTpL1toXGeuuDp5vs2xZW"

FirebaseData firebaseData;
FirebaseConfig config;
FirebaseAuth auth;

int counter = 0; // ตัวแปรสำหรับนับค่า CounterNumber

void setup() {
  Serial.begin(115200);
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

  // กำหนดค่าเริ่มต้นใน Firebase
  if (Firebase.setInt(firebaseData, "/CounterNumber", counter)) {
    Serial.println("Initialized CounterNumber in Firebase");
  } else {
    Serial.println("Failed to initialize CounterNumber: " + firebaseData.errorReason());
  }
}

void loop() {
  // ตรวจสอบว่าค่า counter ถึง 35 หรือยัง
  if (counter < 35) {
    counter++; // เพิ่มค่าทีละ 1
    if (Firebase.setInt(firebaseData, "/CounterNumber", counter)) {
      Serial.printf("Set /CounterNumber to %d\n", counter);
    } else {
      Serial.println("Failed to update CounterNumber: " + firebaseData.errorReason());
    }
    delay(1000); // หน่วงเวลา 1 วินาที (ปรับตามต้องการ)
  } else {
    Serial.println("CounterNumber reached 35. Stopping updates.");
    // ไม่มีการอัปเดตค่าอีกต่อไป
    while (true) {
      delay(1000); // หยุดโปรแกรมที่ loop นี้
    }
  }
}
