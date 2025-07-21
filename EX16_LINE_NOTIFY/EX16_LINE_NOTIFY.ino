#define LINE_TOKEN "TTODDZzhaXNexzwK6C5o0OJ71if76keS3OxL7ohvFcR"

#include <WiFi.h>
#include <WiFiClientSecure.h>

char ssid[] = "MusketBears";
char pass[] = "asd66180";

String txt = "Switch pressed";

#define SWPIN 5

boolean oldstate;
boolean data;

void sendLineNotification(String message) {
  WiFiClientSecure client;
  client.setInsecure(); // ปิดการตรวจสอบใบรับรอง

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("Connection to LINE failed");
    return;
  }

  String payload = "message=" + message;

  client.println("POST /api/notify HTTP/1.1");
  client.println("Host: notify-api.line.me");
  client.println("Authorization: Bearer " + String(LINE_TOKEN));
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(payload.length());
  client.println();
  client.print(payload);

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") break;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(SWPIN, INPUT_PULLUP);
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.print("WiFi Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean currentState = digitalRead(SWPIN);

  if (currentState == LOW && oldstate == HIGH) { // ตรวจจับการกดปุ่ม
    sendLineNotification("%E0%B8%A2%E0%B8%B4%E0%B8%99%E0%B8%94%E0%B8%B5%E0%B8%95%E0%B9%89%E0%B8%AD%E0%B8%99%E0%B8%A3%E0%B8%B1%E0%B8%9A%E0%B8%AA%E0%B8%B9%E0%B9%88%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%AD%E0%B8%9A%E0%B8%A3%E0%B8%A1%E0%B9%80%E0%B8%8A%E0%B8%B4%E0%B8%87%E0%B8%9B%E0%B8%8F%E0%B8%B4%E0%B8%9A%E0%B8%B1%E0%B8%95%E0%B8%B4%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%93%E0%B9%8C%20IoT");
    Serial.println("Button pressed, LINE notification sent.");
  }

  oldstate = currentState;
}
