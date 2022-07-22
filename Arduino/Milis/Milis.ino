//
//unsigned long aktualnyCzas = millis();
//unsigned long zapamietanyCzas = 0;
//unsigned long roznicaCzasu = 0;
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  Serial.println(aktualnyCzas);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  aktualnyCzas = millis();
//  roznicaCzasu = aktualnyCzas - zapamietanyCzas;
//
//  if(roznicaCzasu >= 1000) {
//    zapamietanyCzas = aktualnyCzas;
//    Serial.println(aktualnyCzas);
//  }
//  
////  Serial.println(aktualnyCzas);
////  aktualnyCzas = millis();
//}

#define LED1 3
#define LED2 4

int stanLED1 = LOW;
int stanLED2 = LOW;

unsigned long miganieLED1 = 1000;
unsigned long miganieLED2 = 500;

unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzasLED1 = 0;
unsigned long zapamietanyCzasLED2 = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  
}

void loop(){
  aktualnyCzas = millis();
  if(aktualnyCzas - zapamietanyCzasLED1 >= miganieLED1){
    zapamietanyCzasLED1 = aktualnyCzas;
    stanLED1 = !stanLED1;
  }
  if(aktualnyCzas - zapamietanyCzasLED2 >= miganieLED2){
    zapamietanyCzasLED2 = aktualnyCzas;
    stanLED2 = !stanLED2;
  }

  if(digitalRead(5) == LOW){
    miganieLED1 = 100;
  } else {
    miganieLED1 = 1000;
  }
  
  digitalWrite(LED1, stanLED1);
  digitalWrite(LED2, stanLED2);
}


