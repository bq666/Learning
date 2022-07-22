#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define potencjometr A0
#define led6 9

int odczytanaWartosc = 0 ;
bool razy = false;
int stan = 0;


void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  
}

void loop(){
  odczytanaWartosc = analogRead(potencjometr);
  //Serial.println(odczytanaWartosc);
  analogWrite(led6, odczytanaWartosc);

  
  odczytanaWartosc = map(odczytanaWartosc, 500, 1000, 0, 5);

  if(stan != odczytanaWartosc){
    stan = odczytanaWartosc;
    Serial.println(analogRead (potencjometr));
  }




  if(odczytanaWartosc == 0){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW); 
  }else if(odczytanaWartosc == 1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }else if(odczytanaWartosc == 2){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);    
  }else if(odczytanaWartosc == 3){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);     
  }else if(odczytanaWartosc == 4){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW); 
  }else {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH); 
  }
}






/*
#define GND 13
#define VCC 11
#define dioda 12

int odczytanaWartosc = 0;
float napiecie = 0;
int opoznienie = 0;

void setup(){
  Serial.begin(9600);
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(dioda, OUTPUT);
  digitalWrite(GND,LOW);
  digitalWrite(VCC,HIGH);
}

void loop(){
  odczytanaWartosc = analogRead(A0);
  napiecie = odczytanaWartosc * (5.0/1023.0);
  opoznienie = odczytanaWartosc;
  Serial.print(napiecie);
  Serial.println("V");
  digitalWrite(dioda,LOW);
  delay(opoznienie);
  digitalWrite(dioda,HIGH);
  delay(opoznienie);
}
*/




/*#define zielona 12
#define czerwona 13
boolean stanZielona = false;
boolean stanCzerwona = false;
String odebraneDane = "";
int ileRazy = 0;



void setup(){
  Serial.begin(9600);
  pinMode(zielona, OUTPUT);
  pinMode(czerwona, OUTPUT);
  digitalWrite(zielona, LOW);
  digitalWrite(czerwona, LOW);
}

void loop(){
  if(Serial.available() > 0){
    odebraneDane = Serial.readStringUntil('\n');
    if(odebraneDane == "zielona"){
      if(stanZielona == false){
        digitalWrite(zielona,HIGH);
        stanZielona = true;
      }else{
        digitalWrite (zielona,LOW);
        stanZielona = false;
      }
    }else{
      if(odebraneDane == "czerwona"){
        if(stanCzerwona == false){
          digitalWrite(czerwona,HIGH);
          stanCzerwona = true;
        }else{
          digitalWrite(czerwona,LOW);
          stanCzerwona = false;
        }
      }      
    }
    if(odebraneDane == "zielona" | odebraneDane == "czerwona"){
      Serial.print("Zmieniłem kolor ");
      Serial.print(ileRazy);
      Serial.println(" razy!");
      ileRazy++;
    }else{
      Serial.println("Błędny kolor");  
    }      
  }
}

*/    
    
    
    
    
    
    
    
 
  /*
  digitalWrite(czerwona,HIGH);
  digitalWrite(zielona,LOW);
  delay(100);
  digitalWrite(czerwona,LOW);
  digitalWrite(zielona,HIGH);
  delay(100);


*/



/*
byte licznik = 0;


void setup(){
  Serial.begin(9600);
}

void loop(){
  
  Serial.println(licznik);
  licznik = licznik + 1;
  delay(100);
}
*/



/*#define redLed 13


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Witaj w Arduino!");
  pinMode(redLed,OUTPUT); //czerwona mała
  pinMode(12,OUTPUT); //zielona
  pinMode(11,OUTPUT); //czerwona duża
  pinMode(10,INPUT); 

  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  Serial.println("Ardusrino");
  
}
int x;

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(digitalRead(10) == LOW) {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
  }else{
    //digitalRead(10) == HIGH
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    x++;
    Serial.println("Nasiśnięty");
    Serial.println(x);

    while(digitalRead(10) == HIGH){
      delay(25);
    }
  }
}
*/
