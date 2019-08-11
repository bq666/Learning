//#include <DHT.h>
//#define DHT11_PIN 2
//DHT dht;
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  dht.setup(DHT11_PIN);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  int wilgotnosc = dht.getHumidity();
//  Serial.print(wilgotnosc);
//  Serial.print("%RH | ");
//
//  int temperatura = dht.getTemperature();
//  Serial.print(temperatura);
//  Serial.println("*C");
//
//  delay(1000);
//
//}

#include "DHT.h"
#define DHT11_PIN 2
DHT dht;

void setup()
{
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
}

void loop()
{
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  
  if (dht.getStatusString() == "OK") {
    Serial.print(wilgotnosc);
    Serial.print("%RH | ");
    Serial.print(temperatura);
    Serial.println("*C");
  }
  
  //Odczekanie wymaganego czasugo
  delay(dht.getMinimumSamplingPeriod());
}
