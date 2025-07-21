int LEDPIN = 4;
int SWPIN = 18;
int lastButtonState = 1;
int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWPIN, INPUT_PULLUP);
  digitalWrite(LEDPIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean buttonState = digitalRead(SWPIN);

  if (buttonState == 1 && lastButtonState == 0){
    ledState = !ledState;

    if(ledState) {
      digitalWrite(LEDPIN, HIGH);
      Serial.println("LED ON");
    } else {
      digitalWrite(LEDPIN, LOW);
      Serial.println("LED OFF");
    }
  
    delay(50);
  }

  lastButtonState = buttonState;
}