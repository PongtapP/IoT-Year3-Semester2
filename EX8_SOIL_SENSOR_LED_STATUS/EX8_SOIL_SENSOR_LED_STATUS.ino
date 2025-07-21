int LEDPIN = 4;
#define AOUT_PIN 15

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(AOUT_PIN);
  if(value < 3900){
    digitalWrite(LEDPIN, LOW);
    Serial.println("Normal Status");
  } else {
    digitalWrite(LEDPIN, HIGH);
    Serial.println("Water Inject!");
  }

  Serial.print("Moisture value: ");
  Serial.println(value);

  delay(1000);
}