int LEDPIN = 4;
int LDRSENSOR = 15;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDPIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(LDRSENSOR);
  if(value<1000){
    value=1000;
  }else if(value>3000){
    value=3000;
  }

  int PercentValue = map(value,1000,3000,100,0);

  if(PercentValue<30){
    digitalWrite(LEDPIN,HIGH);
    Serial.println("LED TURN ON");
  }else{
    digitalWrite(LEDPIN,LOW);
    Serial.println("LED TURN OFF");
  }
  Serial.print("LDR persent = ");
  Serial.print(PercentValue);
  Serial.print("% : LDR value");
  Serial.print(value);
  delay(100);
}
