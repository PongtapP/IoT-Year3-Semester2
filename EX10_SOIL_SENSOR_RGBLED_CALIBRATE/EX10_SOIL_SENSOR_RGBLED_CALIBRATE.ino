int R_LEDPIN = 5;
int G_LEDPIN = 18;
int B_LEDPIN = 19;
#define AOUT_PIN 15

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);
  pinMode(R_LEDPIN, OUTPUT);
  pinMode(G_LEDPIN, OUTPUT);
  pinMode(B_LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(AOUT_PIN);

  if(value < 3600){
    value = 3600;
  }else if(value > 4095){
    value = 4095;
  }

  int PercentValue = map(value,3600,4095,100,0);

  if(PercentValue>80){
    digitalWrite(R_LEDPIN, LOW); digitalWrite(G_LEDPIN, HIGH); digitalWrite(B_LEDPIN, LOW);
  }else if(PercentValue<=80 && PercentValue>=40){
    digitalWrite(R_LEDPIN, LOW); digitalWrite(G_LEDPIN, LOW); digitalWrite(B_LEDPIN, HIGH);
  }else if(PercentValue<40){
    digitalWrite(R_LEDPIN, HIGH); digitalWrite(G_LEDPIN, LOW); digitalWrite(B_LEDPIN, LOW);
  }

  Serial.print("Soil Moisture = ");
  Serial.print(PercentValue);
  Serial.print("% : ");
  Serial.println(value);

  delay(100);
}