int SWPIN = 15;
int R_LEDPIN = 5;
int G_LEDPIN = 18;
int B_LEDPIN = 19;
int lastButtonState = 2;
int R_LEDState = 0;
int G_LEDState = 0;
int B_LEDState = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SWPIN, INPUT_PULLUP);
  pinMode(R_LEDPIN, OUTPUT);
  pinMode(G_LEDPIN, OUTPUT);
  pinMode(B_LEDPIN, OUTPUT);
  digitalWrite(R_LEDPIN, LOW);
  digitalWrite(G_LEDPIN, LOW);
  digitalWrite(B_LEDPIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean data = digitalRead(SWPIN);
  if(lastButtonState=2){
    buttonState = 0
  }else if(lastButtonState=1){

  }


  if(buttonState=0){
    digitalWrite(R_LEDPIN, HIGH);
    digitalWrite(G_LEDPIN, LOW);
    digitalWrite(B_LEDPIN, LOW);
  }else if(buttonState=1){
    digitalWrite(R_LEDPIN, LOW);
    digitalWrite(G_LEDPIN, HIGH);
    digitalWrite(B_LEDPIN, LOW);
  }else if(buttonState=2){
    digitalWrite(R_LEDPIN, LOW);
    digitalWrite(G_LEDPIN, LOW);
    digitalWrite(B_LEDPIN, HIGH);
  }


}
