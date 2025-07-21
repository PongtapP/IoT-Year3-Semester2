int RedPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(RedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RedPin, HIGH);
  delay(100);
  digitalWrite(RedPin, LOW);
  delay(100);
}
