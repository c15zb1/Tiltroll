#define XAcc A1
#define YAcc A2
#define ZAcc A3
#define XGyro A4
#define YGyro A5


//Use DLINE
#include <SoftwareSerial.h>


int Accx = 512;
int Accy = 512;
int Accz = 512;
int Gyrox = 512;
int Gyroy = 512;
String SendString = "";

void setup(){

  pinMode (12, OUTPUT);
  digitalWrite(12, HIGH);
  SoftwareSerial mySerial(2,3);

  Serial.begin(9600);
}

void loop(){
  Accx =analogRead(XAcc);
  Accy =analogRead(YAcc);
  Accz =analogRead(ZAcc);
  Gyrox =analogRead(XGyro);
  Gyroy =analogRead(YGyro);

  if(Serial.available()) /*Serial.print("Available")*/;

  SendString = "";
  //  if (Accx < 100) Serial.print("0");
  //  else if (Accx < 10) Serial.print("00");
  //  Serial.print(Accx);
  //    if (Accy < 100) Serial.print("0");
  //  else if (Accy < 10) Serial.print("00");
  //  Serial.print(Accy);
  //    if (Accz < 100) Serial.print("0");
  //  else if (Accz < 10) Serial.print("00");
  //  Serial.print(Accz);
  //    if (Gyrox < 100) Serial.print("0");
  //  else if (Gyrox < 10) Serial.print("00");
  //  Serial.print(Gyrox);
  //    if (Gyroy < 100) Serial.print("0");
  //  else if (Gyroy < 10) Serial.print("00");
  //  Serial.print(Gyroy);
  //  Serial.print("\n"); 

  SendString += Accx;
  SendString += ",";
  SendString += Accy;
  SendString += ",";
  SendString += Accz;
  SendString += ",";
  SendString += Gyrox;
  SendString += ",";
  SendString += Gyroy;
  SendString += '\n';
  Serial.print(SendString);
  delay(100);

}









