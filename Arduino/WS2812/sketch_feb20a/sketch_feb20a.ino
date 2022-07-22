#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel linijka = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800);

#define LED_R 3
#define LED_G 5
#define LED_B 6
#define LED_13 4
 
#define KONTAKTRON 2
//#define PIR 2

volatile int ileRazy = 0;

void setup() {
  pinMode(LED_R, OUTPUT); //Poszczególne piny sterujące diodą jako wyjścia
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
 
  pinMode(KONTAKTRON, INPUT); //Kontaktron jako wejście
//  pinMode(PIR, INPUT); //PIR jako wejście
    
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, LOW);

  attachInterrupt(digitalPinToInterrupt(KONTAKTRON), alarm, FALLING); // Przerwanie reagujące na zbocze rosnące
  linijka.begin();
  linijka.show();

  
}
 
void loop() {
  if (ileRazy < 3) { // Akceptowalnie - kolor zielony
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);    
  } else if (ileRazy < 6) { //Zaczyna być groźnie - kolor niebieski
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);   
  } else { //Alarm - ponad 6 razy wykryto ruch - kolor czerwony
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);       
  }
  if(ileRazy > 8){
    ileRazy = 0;
    int i = 0;
    for(i = 0; i < 9; i++){
      linijka.setPixelColor(i, linijka.Color(0,0,0));
      linijka.show();
    }
  }
  linijka.setPixelColor(ileRazy, linijka.Color(150,0,0));
  linijka.show();
}

void alarm() { //Przerwanie
  ileRazy++; //Wykryto kolejny alarm
}




//void setup() {
//  // put your setup code here, to run once:
//  linijka.begin();
//  linijka.show();  
//  pinMode(3, OUTPUT);
////  pinMode(A5, OUTPUT);
////  pinMode(9, INPUT); //_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(2), ustawAlarm, FALLING);
//
//
//
//
//}

//void loop() {
//  // put your main code here, to run repeatedly:
//
//
//
//  
////  int i = 0;
////  if(digitalRead(2) == LOW){
////    for(i = 0; i < 8; i++){
////      linijka.setPixelColor(i, linijka.Color(100, 0, 0));
////      tone(A5, 3300, 2000);
////    }
////    linijka.show();
////  }
////  if(digitalRead(2) == HIGH){
////    for(i = 0; i < 8; i++){
////      linijka.setPixelColor(i, linijka.Color(0,100,100));
////    }
////    linijka.show();
////  }
//  digitalWrite(3, HIGH);
//  delay(1000);
//  digitalWrite(3, LOW);
//  delay(1000);
//}
//
//  void ustawAlarm() {
//    int i = 0;
//    for(i = 0; i < 8; i++){
//      linijka.setPixelColor(i, linijka.Color(100, 0, 0));
//      tone(A5, 3300, 2000);
//    }
//    linijka.show();  
//    delay(1000);
//
//    for(i = 0; i < 8; i++){
//      linijka.setPixelColor(i, linijka.Color(0,100,100));
//    }
//    linijka.show();
//  
//  }
//
////  tone(A5, 1000, 2000);
////  int hz = 0;
////  for(hz = 3000; hz < 4000; hz++){
////    tone(A5, hz);
////    delay(2);
////  }
////  for(hz = 4000; hz > 3000; hz--){
////    tone(A5, hz);
////    delay(2);
////  }
////  noTone(A5);
////  delay(2000);
//




//  int i = 0;
//  uint32_t kolor = 0;
//  for(i = 0; i < 8; i++){
//    if(i < 4){
//      linijka.setPixelColor(i, linijka.Color(255, 0, 0));
//    } else {
//      linijka.setPixelColor(i, linijka.Color(0, 0, 255));
//    }
//    linijka.show();
//    delay(100);
//  }
//  linijka.clear();


  
//  for(i = 0; i < 8; i++){
//    linijka.setPixelColor(i, linijka.Color(100, 0, 0));
//    linijka.show();
//    delay(200);
//  }
//  
//
//  for(i = 0; i < 8; i++){
//    linijka.setPixelColor(i, linijka.Color(0, 0, 100));
//    linijka.show();
//    delay(200);
//  }
  


