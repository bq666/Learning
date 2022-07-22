

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;



int16_t ax, ay, az;
int16_t gx, gy, gz;

#include "math.h"

#define LED_PIN 13
bool blinkState = false;

#include <Servo.h>

Servo servoZew;
Servo servoWew;
byte pozycja_servoZew = 0;

//boolean pierwsze_dane = true;
int gz_avg, gy_avg, gx_avg = 0 ;
int gz_buff, gy_buff, gx_buff = 0 ;
int i = 1; 
int poz_servo = 1063;
int zm_poz_servo = 0;
int poz_servo_wew = 0;
int poz_servo_wew_buff = 0;
int ilosc_probek_do_avg = 50;
double kat = 0;
double kat_buff = 0;
double kat_ster = 0;
double r = 0;
double c = 0;



void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(115200);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    // configure Arduino LED for
    pinMode(LED_PIN, OUTPUT);
    
    // Calibration
    // accelgyro.setXAccelOffset(0);
    // accelgyro.setYAccelOffset(0);
    // accelgyro.setZAccelOffset(0);

    // accelgyro.setXGyroOffset(-10);
    // accelgyro.setYGyroOffset(4);
    //accelgyro.setZGyroOffset(0);

    // ustawiam serwo zakresy w uS)
    servoZew.attach(5, 800, 1030);
    servoWew.attach(6,1590, 1822);
}

void loop() {
    //accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);   
    accelgyro.getAcceleration(&ax, &ay, &az);
    accelgyro.getRotation(&gx, &gy, &gz);
    gx = gx + 140;
    gy = gy + 200;
    gz = gz + 25;
    ax = ax + 550;
    ay = ay - 530; 

    

//------------------- Zewnętrzny
    zm_poz_servo = map(gz, -11000, 10000, -5, 5);
       
    poz_servo = poz_servo + zm_poz_servo;
    delay(100);
    if(poz_servo > 1030){
      poz_servo = 1030;
    }else if(poz_servo < 800){
      poz_servo = 800;
    }
    servoZew.writeMicroseconds(poz_servo);  


        //Serial.print(ax);Serial.print("\t");
       // Serial.print(ay);Serial.println("\t");
        /*if(gx_buff < ay){
          gx_buff = ay;
        }
        Serial.println(gx_buff);*/
        //Serial.println(az);



//------------------- Wewnętrzny 

    if(abs(ax) > 1000 && abs(ay) > 1000){
        
        if(ax > 0 && ay < 0){       // I ćwiartka 
        Serial.print("I ćwiartka"); Serial.print("\t");
        r = sqrt(pow(ax,2)+pow(ay,2));
        c = (abs(ax)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        Serial.println(kat);
        }
    
        if(ax > 0 && ay > 0){       // II ćwiartka 
        Serial.print("II ćwiartka"); Serial.print("\t");
        r = sqrt(pow(ax,2)+pow(ay,2));
        c = (abs(ay)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        kat = kat + 90;
        Serial.println(kat);
        }    
    
        if(ax < 0 && ay > 0){       // III ćwiartka 
        Serial.print("III ćwiartka");Serial.print("\t");
        r = sqrt(pow(ax,2)+pow(ay,2));
        c = (abs(ax)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        kat = kat + 180;
        Serial.println(kat);
        }    
    
        if(ax < 0 && ay < 0){       // IV ćwiartka 
        Serial.print("IV ćwiartka");Serial.print("\t");
        r = sqrt(pow(ax,2)+pow(ay,2));
        c = (abs(ay)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        kat = kat + 270;
        Serial.println(kat);
        
        }    
        //Serial.print(ax);Serial.print("\t");
        //Serial.print(ay);Serial.println("\t");
        //Serial.println(gz);

        /*if((abs(kat - kat_buff)) > 45){
          if(kat > kat_buff){
            kat = kat_buff + 10;
            kat_buff = kat;
          }
  
          if(kat < kat_buff){
            kat = kat_buff - 10;
            kat_buff = kat;
          }
        }*/
        
        
        /*if(abs(kat - kat_buff) > 10){
          if(kat > kat_buff){
            kat_ster = kat_ster + 10;
            kat_buff = kat;          
          }
          if(kat < kat_buff){
            kat_ster = kat_ster - 10;
            kat_buff = kat;
        }else{
          kat_ster = kat;
         }
        }*/

        poz_servo_wew = map(kat, 360, 0, 1570, 1830);  //1590, 1822);
        //if(poz_servo_wew > 1822){
        //  poz_servo_wew = 1822;
        //}else if(poz_servo_wew < 1590){
        //  poz_servo_wew = 1590;
        //}



       

        /*if(poz_servo_wew > poz_servo_wew_buff){
          poz_servo_wew = poz_servo_wew_buff + 10;
          poz_servo_wew_buff = poz_servo_wew;
        }
        if(poz_servo_wew < poz_servo_wew_buff){
          poz_servo_wew = poz_servo_wew_buff - 10;
          poz_servo_wew_buff = poz_servo_wew;
        }*/
        
        servoWew.writeMicroseconds(poz_servo_wew);  
        }





    







}



//--------------------------------------------------------------

/*//------------------- Wewnętrzny 

    if(abs(gx) > 10000 && abs(gy) > 10000){
        if(gx >= 0 && gy >=0){
        Serial.print("I ćwiartka"); Serial.print("\t");
        r = sqrt(pow(gx,2)+pow(gy,2));
        c = (abs(gy)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        Serial.println(kat);
        }
    
        if(gx >= 0 && gy < 0){
        Serial.print("II ćwiartka"); Serial.print("\t");
        r = sqrt(pow(gx,2)+pow(gy,2));
        c = (abs(gy)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        kat = kat + 90;
        Serial.println(kat);
        }    
    
        if(gx <0 && gy < 0){
        Serial.print("III ćwiartka");Serial.print("\t");
        r = sqrt(pow(gx,2)+pow(gy,2));
        c = (abs(gy)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        kat = kat + 180;
        Serial.println(kat);
        }    
    
        if(gx < 0 && gy >= 0){
        Serial.print("IV ćwiartka");Serial.print("\t");
        r = sqrt(pow(gx,2)+pow(gy,2));
        c = (abs(gy)) / r;
        kat = asin(c);
        kat = kat * (180/PI);
        kat = kat + 225;
        Serial.println(kat);
        
        }    
        Serial.print(gx);Serial.print("\t");
        Serial.print(gy);Serial.print("\t");
        //Serial.println(gz);

        poz_servo_wew = map(kat, 0, 360, 1590, 1822);
        servoWew.writeMicroseconds(poz_servo_wew);  
    }
*/




    /*
         zm_poz_servo = map(gz, -11000, 10000, -5, 5);
    //Serial.print("\t"); Serial.print(zm_poz_servo);
    poz_servo = poz_servo + zm_poz_servo;
    delay(100);
    
    Serial.print("\t"); Serial.println(poz_servo);

    
    //Serial.print("\t");Serial.println(gz_avg);

    servoZew.writeMicroseconds(poz_servo);
     */



/*
    for(int i = 1; i <= ilosc_probek_do_avg; i++){
      gx_avg = gx_avg + gx;
      if(i = ilosc_probek_do_avg){
        gx_avg = gx_avg / ilosc_probek_do_avg; 
      }
    }    

    for(int i = 1; i <= ilosc_probek_do_avg; i++){
      gy_avg = gy_avg + gy;
      if(i = ilosc_probek_do_avg){
        gy_avg = gy_avg / ilosc_probek_do_avg; 
      }
    }

    for(int i = 1; i <= ilosc_probek_do_avg; i++){
      gz_avg = gz_avg + gz;
      if(i = ilosc_probek_do_avg){
        gz_avg = gz_avg / ilosc_probek_do_avg; 
      }
    }


*/


/*
    gx_buff = gx_buff + gx;
    gy_buff = gy_buff + gy;
    gz_buff = gz_buff + gz; 
    //Serial.print(gx_avg);Serial.println("\t");  
    i++;

    if(i == ilosc_probek_do_avg){
    i = 1;
    gx_avg = gx_buff / ilosc_probek_do_avg; 
    gy_avg = gy_buff / ilosc_probek_do_avg; 
    gz_avg = gz_buff / ilosc_probek_do_avg;    

    gx_buff = 0;
    gy_buff = 0;
    gz_buff = 0;

    //gx_avg=gx_avg + 140;
   // gy_avg=gy_avg + 200;
    //gz_avg=gz_avg + 25;

    Serial.print(gx_avg);Serial.print("\t");
    Serial.print(gy_avg);Serial.print("\t");
    Serial.println(gz_avg); 


    }
*/
