void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);  
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT_PULLUP);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(100);
  
  while(digitalRead(10) == LOW){}

    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    delay(100);

  while(digitalRead(10) == LOW){}

    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    delay(100);
    
  while(digitalRead(10) == LOW){}

/*    
  
  while(digitalRead(10) == HIGH){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }
*/

/*
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(1000);
  
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  delay(1000);

  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  delay(1000);

  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  delay(1000);

  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  delay(1000);
*/
  
  /*if(digitalRead(10) == HIGH){
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(1000);
  }
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  */

  
  /*digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  delay(15);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  delay(15);
  if(digitalRead(10) == HIGH){
    delay(5000);
  }*/
}
