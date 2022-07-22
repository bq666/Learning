#define trigPin 7
#define echoPin 8
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
}
 
void loop() {
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
 
  if (dystans > 400) { //Jeśli obliczona odległość jest większa od 400
    dystans = 400; //to ustaw ją na 400 (max wskazane przez producenta)
  }
  
  Serial.println(dystans);
  delay(100);
}
