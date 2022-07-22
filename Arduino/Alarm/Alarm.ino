#define BUZZER 11
#define KONTAKTRON 10
#define PIR 1
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>


const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

int pinAlarmuPozycja = 1;
char pinCyfra1 = '1';
char pinCyfra2 = '2';
char pinCyfra3 = '3';
char pinCyfra4 = '4';

int ileCzasuMinelo = 0;

Keypad klawiatura = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel linijka = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800);


volatile int stanAlarmu = 1;

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(KONTAKTRON, INPUT_PULLUP);
  pinMode(PIR, INPUT_PULLUP);

  linijka.begin();
  linijka.show();
}

void loop() {
  // put your main code here, to run repeatedly:
//  char klawisz = klawiatura.getKey();

//  if(klawisz){
//    Serial.println(klawisz);
//  }
  char klawisz = 0;
  int i = 0;

  switch(stanAlarmu){
    case 1:
    //czuwanie
      linijka.setPixelColor(0, linijka.Color(0, 15, 0));
      linijka.show();
  
      klawisz = klawiatura.getKey();
      if(klawisz == 'A'){
        for(i = 1; i < 8; i++){
          linijka.setPixelColor(i, linijka.Color(0,0,15));
          linijka.show();
          delay(710);
        }
        for(i = 1; i < 8; i++){
          linijka.setPixelColor(i, linijka.Color(15,0,0));
          linijka.show();
          delay(710);
        }
        wylaczDiody();
        stanAlarmu = 2;
      }    
    break;

    case 2:
    //monitorowanie
      linijka.setPixelColor(7, linijka.Color(15,0,0));
      linijka.show();
      delay(50);
      linijka.setPixelColor(7, linijka.Color(0,0,0));
      linijka.show();
      delay(50);
  
      if(digitalRead(PIR) == HIGH){
        stanAlarmu = 4;
      } else if(digitalRead(KONTAKTRON) == HIGH){
        stanAlarmu = 3;
      }
    
    break;

    case 3:
    //rozbrajanie
      klawisz = klawiatura.getKey();
      if(klawisz){
        if(pinAlarmuPozycja == 1 && klawisz == pinCyfra1){
          pinAlarmuPozycja++;
        } else if(pinAlarmuPozycja == 2 && klawisz == pinCyfra2){
          pinAlarmuPozycja++;
        } else if(pinAlarmuPozycja == 3 && klawisz == pinCyfra3){
          pinAlarmuPozycja++;
        } else if(pinAlarmuPozycja == 4 && klawisz == pinCyfra4){
          stanAlarmu = 1;
        } else {
          stanAlarmu = 4;
        }
      }
      delay(100);
      ileCzasuMinelo++;
 
      if (ileCzasuMinelo >= 50) {
        stanAlarmu = 4;
      }

    break;

    case 4:
    //alarm
      for(i = 0; i < 8; i++){
        linijka.setPixelColor(i, linijka.Color(255,0,0));        
      }
      linijka.show();
      tone(BUZZER, 4300);
      delay(100);

      for(i = 0; i < 8; i++){
        linijka.setPixelColor(i, linijka.Color(0,0,255));
      }
      linijka.show();
      tone(BUZZER, 3500);
      delay(100);

    break;
  }

}

void wylaczDiody(){
  int i = 0;
  for(i = 0; i < 8; i++){
    linijka.setPixelColor(i, linijka.Color(0,0,0));
  }
  linijka.show();
}

