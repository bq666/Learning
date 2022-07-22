#define OUT1 2
#define OUT2 3
#define PWM 5
#define Trig 7
#define Echo 8
#define Buz A0

int i = 0;
String odebrane;
String _speed = "999";
int czas = 3000;
int szybkosc = 100;
int pwm = 0;
boolean test = false;
int odl = 0;
int odlb = 0;

void lewo();
void prawo();


void setup() {
  // put your setup code here, to run once:
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(PWM, OUTPUT);
  analogWrite(PWM,80);
  Serial.begin(9600);
  Serial.println("Podaj kierunek (prawo,lewo) lub zmień prędkość (speed) lub zobacz odległość (odleglosc) lub (losuj):");
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT_PULLUP);

  randomSeed(analogRead(A0));
  for(int i = 0; i <= 20; i++){
    
    Serial.println(random(300));
  }

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    if(Serial.available() > 0){
      odebrane = Serial.readStringUntil('\n');     
        if(odebrane == "prawo"){
            prawo();
            Serial.println("Aktualny kierunek prawo");
        }else if(odebrane == "lewo"){
            lewo();
            Serial.println("Akktualny kierunek lewo");
        }else if(odebrane == "speed"){
          Serial.println("Podaj predkosc (0 - 255):");
            //Serial.println(_speed);
            //delay(3000);
            while(test == false){                
              if(Serial.available() > 0){          
                _speed = Serial.readStringUntil('\n');
                Serial.print("Aktualna prędkość: ");
                Serial.println(_speed);
                Serial.println("Podaj kierunek (prawo,lewo) lub zmień prędkość (speed) lub zobacz odległość (odleglosc) lub losuj (losuj):");
                
                pwm = _speed.toInt();                
                analogWrite(PWM,pwm);
                test = true;          
              }
            }  
        }else if(odebrane == "odleglosc"){
          while(Serial.available() == 0){
            digitalWrite(Trig, LOW);
            delayMicroseconds(2);
            digitalWrite(Trig, HIGH);
            delayMicroseconds(10);
            digitalWrite(Trig,LOW);
            odl = pulseIn(Echo, HIGH);
            //Serial.println(odl);
            odl = odl / 58;
            if(odl > (odlb + 10) || odl < (odlb - 10)){
              odl = odlb; 
            }else{
              odlb = odl;
            }


            //Serial.println(odl);
            Serial.print("Odległość: ");Serial.print(odl);Serial.println(" cm (aby wyjść nadzisnij cokolwiek)");       
            odl = map(odl, 1, 200, 1500, 1); 
            tone(Buz, odl);        
          }            
          //Serial.println("test"); 
          pinMode(Buz, INPUT_PULLUP);   
          //digitalWrite(Buz,LOW);
        }else if(odebrane == "losuj"){
          for(int i = 0; i <= 1000; i++){
           Serial.println(random(300));
          }
          
          
        }else if(odebrane != 0){
          test = true;
        }
    }
    if(test == false){
      Serial.println("Podaj kierunek (prawo,lewo) lub zmień prędkość (speed) lub zobacz odległość (odleglosc) lub losuj (losuj):");
    }
    test = false;
  }    
}


void lewo(){
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    for(int i = 0; i <= pwm; i++){
      analogWrite(PWM, i);
      delay(15);
    }
}

void prawo(){
    digitalWrite(OUT1,LOW);
    digitalWrite(OUT2,HIGH);
    for(int i = 0; i <= pwm; i++){
      analogWrite(PWM, i);
      delay(15);
    }
}




