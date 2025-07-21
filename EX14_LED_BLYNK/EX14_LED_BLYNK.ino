#define BLYNK_TEMPLATE_ID "TMPL61Z9Z0rDX"
#define BLYNK_TEMPLATE_NAME "ESP32 PONGTAP"
#define BLYNK_AUTH_TOKEN "hjsnBMHYaxm16p64Z4-ttKABF5mhhaJp"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "MusketBears";    // ใส่ชื่อ WiFi ของคุณ
char pass[] = "asd66180"; // ใส่รหัสผ่าน WiFi ของคุณ

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(4, OUTPUT);   
}

BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // รับค่าจากแอป (0 หรือ 1)
  digitalWrite(4, pinValue);   // เขียนค่าไปที่ GPIO4
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
