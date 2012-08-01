#define XAcc A1
#define YAcc A2
#define ZAcc A3
#define XGyro A4
#define YGyro A5


//Use DLINE
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);

int Accx = 512;
int Accy = 512;
int Accz = 512;
int Gyrox = 512;
int Gyroy = 512;

void setup(){
  mySerial.begin(9600);
}

void loop(){
  Accx =analogRead(XAcc);
  Accy =analogRead(YAcc);
  Accz =analogRead(ZAcc);
  Gyrox =analogRead(XGyro);
  Gyroy =analogRead(YGyro);

  if(mySerial.available()) mySerial.print("Available");
  mySerial.print(".");
  if (Accx < 100) mySerial.print("0");
  else if (Accx < 10) mySerial.print("00");
  mySerial.print(Accx);
    if (Accy < 100) mySerial.print("0");
  else if (Accy < 10) mySerial.print("00");
  mySerial.print(Accy);
    if (Accz < 100) mySerial.print("0");
  else if (Accz < 10) mySerial.print("00");
  mySerial.print(Accz);
    if (Gyrox < 100) mySerial.print("0");
  else if (Gyrox < 10) mySerial.print("00");
  mySerial.print(Gyrox);
    if (Gyroy < 100) mySerial.print("0");
  else if (Gyroy < 10) mySerial.print("00");
  mySerial.print(Gyroy);
  mySerial.print("\n"); 

  delay(100);

}







