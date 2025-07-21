#define AOUT_PIN 15
int R_LEDPIN =5;
int G_LEDPIN =18;
int B_LEDPIN =19;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // analogSetAttenuation(ACD_11db);
  pinMode(R_LEDPIN, OUTPUT);
  pinMode(G_LEDPIN, OUTPUT);
  pinMode(B_LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(AOUT_PIN);
  if(value<1900){
    value = 1900;
  }else if(value>3300){
    value = 3300;
  }

  int PercentValue=map(value,1900,3300,100,0);
  if(PercentValue>80){
    digitalWrite(R_LEDPIN, LOW);
    digitalWrite(G_LEDPIN, HIGH);
    digitalWrite(B_LEDPIN, LOW);
  }else if(PercentValue<=80&&PercentValue>=40){
    digitalWrite(R_LEDPIN, LOW);
    digitalWrite(G_LEDPIN, LOW);
    digitalWrite(B_LEDPIN, HIGH);
  }else if(PercentValue<40){
    digitalWrite(R_LEDPIN, HIGH);
    digitalWrite(G_LEDPIN, LOW);
    digitalWrite(B_LEDPIN, LOW);
  }
  Serial.print("Soil Moisture = ");
  Serial.print(PercentValue);
  Serial.print("% : ");
  Serial.println(value);
  delay(100); // this speeds up the simulation
}
