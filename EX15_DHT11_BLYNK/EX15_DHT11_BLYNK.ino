#define BLYNK_TEMPLATE_ID "TMPL61Z9Z0rDX"
#define BLYNK_TEMPLATE_NAME "ESP32 PONGTAP"
#define BLYNK_AUTH_TOKEN "hjsnBMHYaxm16p64Z4-ttKABF5mhhaJp"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleDHT.h>

char ssid[] = "MusketBears";
char pass[] = "asd66180";

int DHTSENSOR = 15;

SimpleDHT22 dht22;

BlynkTimer timer;

void sendSensor(){
  byte temperature = 0;
  byte humidity = 0;

  dht22.read(DHTSENSOR, &temperature, &humidity, NULL);
  while (temperature == 0){
    dht22.read(DHTSENSOR, &temperature, &humidity, NULL);
    Serial.println("DHT22 get failed");
    delay(1500);
  }

  Blynk.virtualWrite(V2, temperature);
  Blynk.virtualWrite(V1, humidity);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendSensor); // ตั้งเวลาให้เรียก sendSensor() ทุก 2 วินาที
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
