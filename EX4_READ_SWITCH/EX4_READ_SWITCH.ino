int LEDPIN = 4;
int SWPIN = 18;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWPIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean data = digitalRead(SWPIN);

  if(data == 0){
    digitalWrite(LEDPIN, HIGH);
    Serial.println("LED ON");
  } else {
    digitalWrite(LEDPIN, LOW);
    Serial.println("LED OFF");
  }
}