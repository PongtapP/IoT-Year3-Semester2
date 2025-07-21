#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <esp_sleep.h>
#include <SimpleDHT.h>

char ssid[] = "MusketBears";
char pass[] = "asd66180";

#define LINE_TOKEN "JdcMHPGIHGKDI2WPWh9LePuFTP7rpxfhDVXnGV6RYWs"
int DHTSENSOR = 15;

SimpleDHT22 dht22;
unsigned long last1, last2, last3;

void sendLineNotification(float temp, float hum) {

  WiFiClientSecure client;
  client.setInsecure(); // ปิดการตรวจสอบใบรับรอง

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("Connection to LINE API failed!");
    return;
  }

  // String message = "ESP32""\nTemperature: " + String(temp) + "°C\nHumidity: " + String(hum) + "%";
  // String payload = "message=" + message;
  String payload = "message=" + String("ESP32%0A") + "Temperature%3A " + String(temp) + "%C2%B0C%0AHumidity%3A " + String(hum) + "%25";

  String request = String("POST /api/notify HTTP/1.1\r\n") +
    "Host: notify-api.line.me\r\n" +
    "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n" +
    "Content-Type: application/x-www-form-urlencoded\r\n" +
    "Content-Length: " + String(payload.length()) + "\r\n" +
    "Connection: close\r\n\r\n" +
    payload;

  client.print(request);
  Serial.println("Waiting for response...");
  while (client.available()) {
    String response = client.readString();
    Serial.println(response);
  }
  Serial.println("Sent request to LINE Notify");

  // อ่านค่าตอบกลับจากเซิร์ฟเวอร์
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
  Serial.println("LINE Notification sent!");
  client.stop();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Wake up.");

    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected");

    byte temperature = 0;
    byte humidity = 0;
    byte data[40] = {0};

    if (dht22.read(DHTSENSOR, &temperature, &humidity, data) == 0) {
        Serial.print("Temperature: "); Serial.print(temperature); Serial.println("°C");
        Serial.print("Humidity: "); Serial.print(humidity); Serial.println("%");
        sendLineNotification(temperature, humidity);
    } else {
        Serial.println("Failed to read from DHT22 sensor");
    }

    Serial.println("Entering deep sleep for 1 minute...");
    esp_sleep_enable_timer_wakeup(60 * 1000000);
    esp_deep_sleep_start();
}

void loop() {
  // put your main code here, to run repeatedly:
}