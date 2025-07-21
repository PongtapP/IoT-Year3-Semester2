int R_LEDPIN =5;
int G_LEDPIN =18;
int B_LEDPIN =19;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(R_LEDPIN, OUTPUT);
  pinMode(G_LEDPIN, OUTPUT);
  pinMode(B_LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R_LEDPIN, HIGH);
  digitalWrite(G_LEDPIN, LOW);
  digitalWrite(B_LEDPIN, LOW);
  delay(1000);
  digitalWrite(R_LEDPIN, LOW);
  digitalWrite(G_LEDPIN, HIGH);
  digitalWrite(B_LEDPIN, LOW);
  delay(1000);
  digitalWrite(R_LEDPIN, LOW);
  digitalWrite(G_LEDPIN, LOW);
  digitalWrite(B_LEDPIN, HIGH);
  delay(1000);

}
