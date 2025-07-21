#define AOUT_PIN 15
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(AOUT_PIN);

  Serial.print("Moisture value: ");
  Serial.println(value);

  delay(500);
}