int SWPIN = 18;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SWPIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(SWPIN);
  Serial.println(data);
  delay(100);
}