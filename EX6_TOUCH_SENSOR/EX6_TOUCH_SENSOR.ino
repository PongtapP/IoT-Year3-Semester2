void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 TOUCH TEST");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(touchRead(T3));
  delay(100);
}
