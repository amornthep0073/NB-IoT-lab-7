#include <DHT.h>;
#include "Magellan_BC95.h"
#define DHTTYPE DHT22 
#define DHTPIN 7
Magellan_BC95 magel;

char auth[] ="20d785a4-283e-46f0-965f-f33b48be82e5";
String payload;
DHT dht (DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  magel.begin(auth);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  String Temepature = String(t);
  String Humidity = String(h);
  payload ="{\"Temperature\":"+Temperature+",\"Humidity\":"+Humidity+"}";
  magel.post(payload);
  
}
