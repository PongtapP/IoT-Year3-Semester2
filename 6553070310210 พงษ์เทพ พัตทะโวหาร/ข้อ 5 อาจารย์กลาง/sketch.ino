int LDRSENSOR = 15;
int LEDPIN = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(LDRSENSOR);
  if(value<0){
    value=0;
  }else if(value>2000){
    value=2000;
  }
  int PercentValue = map(value,0,2000,100,0);
  if(PercentValue<30){
    digitalWrite(LEDPIN, HIGH);
  }else{
    digitalWrite(LEDPIN, LOW);
  }
  Serial.print("LDR percent = ");
  Serial.print(PercentValue);
  Serial.print("% : LDR value = ");
  Serial.println(value);
  delay(100); // this speeds up the simulation
}
