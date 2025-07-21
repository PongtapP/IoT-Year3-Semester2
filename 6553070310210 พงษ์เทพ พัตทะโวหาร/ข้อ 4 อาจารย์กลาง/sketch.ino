#include <SimpleDHT.h>
int DHTPIN=0;
SimpleDHT22 dht22;
byte temperature = 0;
byte humidity = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  dht22.read(DHTPIN,&temperature,&humidity,NULL);
  delay(1000); // this speeds up the simulation
  Serial.print("DHT22 read: ");
  Serial.print((int)temperature);
  Serial.print(" *C, ");
  Serial.print((int)humidity);
  Serial.println(" %H");
}
