#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

float czas = 0;
int jasnosc = 0;

void resetLcd(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Stoper");
  lcd.setCursor(0,1);
  lcd.print("0.00 s");
}


void setup(){
  Serial.begin(9600);
  resetLcd();
  //lcd.blink();
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop(){
  jasnosc = analogRead(A0);
  Serial.println(jasnosc);
  jasnosc = map(jasnosc, 0, 920, 0, 255);
  analogWrite(11, jasnosc);
  if(digitalRead(8) == LOW){
    while(digitalRead(9) != LOW){
      lcd.setCursor(0,1);
      lcd.print(czas);
      czas = czas + 0.00255;
      digitalWrite(12,HIGH);
      digitalWrite(12,LOW);
    }
  }
  
  
  if(digitalRead(10) == LOW){
    czas = 0.0;    
    resetLcd();
    lcd.setCursor(0,1);
    lcd.print(czas);
  }




 /* 
  float nap = analogRead(A0);
  lcd.setCursor(0,1);
  lcd.print(nap*5.0/1119.0);
  delay(550);
 */ 
  
  //lcd.noDisplay();
  //delay(500);
  //lcd.display();
  //delay(500); 
}






















/*
int odebraneDane = "";

void setup(){
  Serial.begin(9600);
}

void loop(){
  int potencjometr = analogRead(A0);

  if(Serial.available() > 0){
    odebraneDane = Serial.read();
  }

  switch(odebraneDane){
    case 'd':
      Serial.println(potencjometr, DEC);
    break;
    case 'h':
      Serial.println(potencjometr, HEX);
    break;
    case 'o':
      Serial.println(potencjometr, OCT);
    break;
    case 'b':
      Serial.println(potencjometr, BIN);
    break;
  }
  delay(1000);
}
*/














/*
float pierwszy = 0;
float drugi = 0;
float trzeci = 0;



void setup(){
  Serial.begin(9600); 
  pinMode(5, INPUT_PULLUP);
}



void loop(){
  pierwszy = analogRead(A0);
  drugi = analogRead(A1);
  trzeci = analogRead(A2);
  //Serial.println(pierwszy);
  if(digitalRead(5) == LOW){
    Serial.print(pierwszy/205);
    Serial.print(" [V]");
    Serial.print("\t");

    Serial.print(drugi/205);
    Serial.print(" [V]");
    Serial.print("\t");

    Serial.print(trzeci/205);
    Serial.print(" [V]");
    Serial.println("\t");
  }
 
 
}
*/











/*
 *   for(int i = 0; i <= 255;i++){ 
    Serial.println(liczba, DEC);
    Serial.println(liczba, HEX);
    Serial.println(liczba, OCT);
    Serial.println(liczba, BIN);
    Serial.println("------------)");
    //liczba++;
    delay(1000);
 */









/*
#include <Servo.h>

Servo serwomechanizm;
int pozycja = 0;
int zmiana = 6;
int zmianaczas = 50;
int czas = 200;
int odebrane_dane = 0;

void setup() {
  // put your setup code here, to run once:
  serwomechanizm.attach(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   odebrane_dane = analogRead(A0);
   Serial.print(odebrane_dane);
   Serial.print("            ");
   odebrane_dane = map(odebrane_dane, 900, 1000, 0, 180);
   Serial.println(odebrane_dane);
   serwomechanizm.write(odebrane_dane);
   delay(10);
*/  
  
  
  
  
  
  
  
  
  

  
  
  
  
/*  
  if(Serial.available() > 0){
    odebrane_dane = Serial.readBytes(byte[],3);
    Serial.println(odebrane_dane);
      if(odebrane_dane >= 0 && odebrane_dane <= 180){
        serwomechanizm.write(odebrane_dane);
      }else{
        Serial.println("złe dane");
      }    
  }    
}
*/
