#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel linijka = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800);


#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(11);
DallasTemperature sensors(&oneWire);
DeviceAddress pierwszy = {0x28, 0x08, 0x05, 0xE3, 0x07, 0x00, 0x00, 0xD6};
DeviceAddress drugi = {0x28, 0xF2, 0xE2, 0xE2, 0x07, 0x00, 0x00, 0x6F};

#include <SevSeg.h>
SevSeg sevseg;



byte numDigits = 2;
byte digitPins[] = {10,9};
byte segmentPins[] = {7, 5, 2, 4, 3, 8, 6};
bool resistorsOnSegments = true;
byte hardwareConfig = N_TRANSISTORS;



#define SEG_C 2
#define SEG_E 3
#define SEG_D 4
#define SEG_B 5
#define SEG_G 6
#define SEG_A 7
#define SEG_F 8

#define WYSW_1 10
#define WYSW_2 9

void setup() {
  //Konfiguracja pinow jako wyjscia
//  pinMode(SEG_A, OUTPUT);
//  pinMode(SEG_B, OUTPUT);
//  pinMode(SEG_C, OUTPUT);
//  pinMode(SEG_D, OUTPUT);
//  pinMode(SEG_E, OUTPUT);
//  pinMode(SEG_F, OUTPUT);
//  pinMode(SEG_G, OUTPUT);
//
//  pinMode(WYSW_1, OUTPUT);
//  pinMode(WYSW_2, OUTPUT);  
  Serial.begin(9600);
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);


  sensors.begin();

  linijka.begin();
}

int ii = 0;
float start = 0;

void loop() {
//    digitalWrite(WYSW_1, HIGH); //Włącz pierwszy wyświetlacz
//    digitalWrite(WYSW_2, LOW); //Wyłącz drugi
//    wyswietlacz(5); //Wyswietl wartosc na wyswietlaczu
//    delay(10);
//    digitalWrite(WYSW_1, LOW); //Wyłącz pierwszy wyświetlacz
//    digitalWrite(WYSW_2, HIGH); //Włącz drugi
//    wyswietlacz(3); //Wyswietl wartosc na wyswietlaczu
//    delay(10);
  
//  start = millis();
//  wysw2(ii);
//  if((millis() - start) >= 1000){
//    ii++;
//    start = millis();
//  }
////  Serial.print(start);
////  Serial.print("   ");
////  Serial.println(millis()); 
//  Serial.println(ii);

  int i = analogRead(A0);
//  i = map(i, 0, 1023, 0, 50);
  float temp = ((i * 5.0) / 1023.0) * 100;
  float tempp = ((analogRead(A1) * 5.0) / 1023.0) * 100;
  sevseg.setNumber(i);
  sevseg.refreshDisplay();
//  Serial.print(temp); 
//  Serial.print("   ");
//  Serial.print(tempp);
//  Serial.print("   ");
//  Serial.println(tempp - temp);


  sensors.requestTemperatures();
  Serial.print(sensors.getTempC(pierwszy));
  Serial.print("   ");
  Serial.println(sensors.getTempC(drugi));

  termometrRGB(sensors.getTempC(drugi)); 
  
} // end loop()


void wysw2(int liczba){
  int a = liczba / 10;
  int b = liczba % 10;
//  Serial.print(a);
//  Serial.print("  ");
//  Serial.println(b);
  digitalWrite(WYSW_1, HIGH);
  digitalWrite(WYSW_2, LOW);
  wyswietlacz(a);
  delay(10);
  digitalWrite(WYSW_1, LOW);
  digitalWrite(WYSW_2, HIGH);
  wyswietlacz(b);
  delay(10);
}

void termometrRGB(int temperatura) {
  //Sprawdzamy, czy temperatura jest w odpowiednim zakresie
  if (temperatura > 40) {
    temperatura = 40;
  } else if (temperatura < -40) {
    temperatura = -40;
  }
 
  //Wyczysc linijkę
  linijka.clear();
  
  if (temperatura >= 0) {
    //Dla wartosci dodatnich
     temperatura = map(temperatura, 0, 40, 1, 8); 
      
     int i = 0;
     for (i = 0; i < temperatura; i++) {
        linijka.setPixelColor(i, linijka.Color(255, 0, 0)); //Dioda nr i świeci na czerwono
     }
     
  } else {
    //Dla wartosci ujemnych
     temperatura = map(temperatura, -40, 0, 1, 8);
     int i = 0;
     for (i = 8; i > temperatura; i--) {
        linijka.setPixelColor(i, linijka.Color(0, 0, 255)); //Dioda nr i świeci na niebiesko
     }
  }
 
  linijka.show(); 
}


void wyswietlacz(int cyfra) {
  //Instrukcja switch ustawia odpowiednie stany na wyjsciach
  //w zaleznosci od podanej cyfry
  switch (cyfra) {
    case 0:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, LOW);
    break; 
    
    case 1:
        digitalWrite(SEG_A, LOW);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, LOW);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, LOW);
    break; 
    
    case 2:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, LOW);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 3:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 4:
        digitalWrite(SEG_A, LOW);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, LOW);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 5:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, LOW);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 6:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, LOW);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break;
   
    case 7:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, LOW);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, LOW);
    break;
    
    case 8:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break;
    
    case 9:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break;
  }
}
