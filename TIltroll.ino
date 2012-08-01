/* Motor Pin Definitions */
#define INa1 10
#define INb1 11
#define PWM1 8
#define INa2 12
#define INb2 13
#define PWM2 9
#define cc 7//cruise control

#define SOP '.'
#define EOP '\n'

#include <SoftwareSerial.h>


/* Variable Definitions */
int speed1;
int speed2;
int turnFactor;

String data = "";
int AccX;
int AccY;
int AccZ;
int GyroX;
int GyroY;
byte index;
/* Variables to deal with data recieved from the XBee */
//int init;
int coma1;
int coma2;
int coma3;
int coma4;
int ii;
int comaNum;
String data1 = "";
String x ="";
String y ="";
String z ="";
String xg ="";
String yg ="";
boolean ended;
boolean started;

String inData[80];

/* Cruise Controll*/
boolean cruise = false;
boolean ready = false; 


void setup(){

  //USE UART
  Serial.begin(9600);
  pinMode(INa1, OUTPUT);
  pinMode(INb1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(INa2, OUTPUT);
  pinMode(INb2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(cc, INPUT);
  Serial.print("Setup");

}

void loop(){
  Serial.println("In the loop");

  //  ii = 0;
  //  while(Serial.read()!= '.');
  //  Serial.print("Got a Period");
  //  while(Serial.available()==0);
  //  Serial.print("Available");
  //  int val = Serial.read(); //read in one byte
  //  AccX = 100*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccX = AccX + 10*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccX = AccX + (val-'0');
  //  Serial.println(AccX);
  //  //We're done reading the first value
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccY = 100*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccY = AccY + 10*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccY = AccY + (val-'0');
  //  Serial.println(AccY);
  //  //We're done reading the first value
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccZ = 100*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccZ = AccZ + 10*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  AccZ = AccZ + (val-'0');
  //  Serial.println(AccZ);
  //  //We're done reading the first value
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  GyroX = 100*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  GyroX = GyroX + 10*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  GyroX = GyroX + (val-'0');
  //  Serial.println(GyroX);
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  GyroY = 100*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  GyroY = GyroY + 10*(val-'0');
  //  while(Serial.available()==0);
  //  val = Serial.read(); //read in one byte
  //  GyroY = GyroY + (val-'0');
  //  Serial.println(GyroY);
  //We're done reading the first value
  //We're done reading the first value
  //  comaNum = 0;
  //  for(int kk=0; kk<30; kk++){
  //    if(data[kk] == ','){
  //      if(comaNum == 0)
  //        coma1 = data.charAt(kk);
  //      else if(comaNum == 1)
  //        coma2 = data.charAt(kk);
  //      else if(comaNum == 2)
  //        coma3 = data.charAt(kk);
  //      else if(comaNum == 3)
  //        coma4 = data.charAt(kk);
  //      comaNum++;
  //    }
  //  }
  //  for(int jj = 0; jj<data.length(); jj++){
  //    data1 += data.charAt(jj);
  //  }
  //  AccX = getVals(data1. substring(0, coma1));
  //  AccY = getVals(data1.substring(coma1+1, coma2));
  //  AccZ = getVals(data1.substring(coma2+1, coma3));
  //  GyroX = getVals(data1.substring(coma3+1, coma4));
  //  GyroY = getVals(data1.substring(coma4+1));

  if(ready){
    interpretSerial();  
  }
  setmotors(GyroX, GyroY);


  //  Serial.print("I got");
  //  Serial.print(data);
  //  Serial.print("\n");
  //  Serial.println("And made it");
  //  Serial.print(".");
  //  Serial.print(AccX);
  //  Serial.print(",");
  //  Serial.print(AccY);
  //  Serial.print(",");
  //  Serial.print(AccZ);
  //  Serial.print(",");
  //  Serial.print(GyroX);
  //  Serial.print(",");
  //  Serial.print(GyroY);
  //  Serial.print("\n");
}

void setmotors(int zAcc, int yAcc){

  if(!cruise){
    if (zAcc>=500 && zAcc<=524){
      digitalWrite(INa1, HIGH);
      digitalWrite(INb1, HIGH);
      digitalWrite(INa2, HIGH);
      digitalWrite(INb2, HIGH); 
    }
    else if (zAcc>524){
      digitalWrite(INa1, LOW);
      digitalWrite(INb1, HIGH);
      digitalWrite(INa2, LOW);
      digitalWrite(INb2, HIGH);
    }
    else if (zAcc<500){
      digitalWrite(INa1, HIGH);
      digitalWrite(INb1, LOW); 
      digitalWrite(INa2, HIGH);
      digitalWrite(INb2, LOW); 
    }
    speed1 = map(zAcc, 0, 1023, 0, 255);
    speed2 = map(zAcc, 0, 1023, 0, 255);
    turnFactor = map(yAcc, 0, 1023, -255 , 255);

    if (turnFactor>24){
      speed1 -= turnFactor; 
    }
    else if (turnFactor<-24){
      speed2 -= -1*turnFactor;
    }
    analogWrite(PWM1, speed1);
    analogWrite(PWM2, speed2);
  }
}




int getVals(String in){

  if(in.length() == 1)
    return in.charAt(0)-48;
  else if(in.length() == 2)
    return ((in.charAt(0)-48)*10)+(in.charAt(1)-48);
  else if(in.length() == 3)
    return ((in.charAt(0)-48)*100)+((in.charAt(1)-48)*10)+(in.charAt(2)-48);
  else if(in.length() == 3)
    return 1000+((in.charAt(1)-48)*100)+((in.charAt(2)-48)*10)+(in.charAt(3)-48);
}














