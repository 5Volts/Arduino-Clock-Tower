// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
   #define Serial SerialUSB
#endif

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  pinMode(30,OUTPUT);
pinMode(32,OUTPUT);
pinMode(34,OUTPUT);
pinMode(36,OUTPUT);
pinMode(38,OUTPUT);
pinMode(40,OUTPUT);
pinMode(42,OUTPUT);
pinMode(44,OUTPUT);
pinMode(46,OUTPUT);
pinMode(48,OUTPUT);
pinMode(50,OUTPUT);
pinMode(52,OUTPUT);
pinMode(31,OUTPUT);
pinMode(33,OUTPUT);
pinMode(35,OUTPUT);
pinMode(37,OUTPUT);
pinMode(39,OUTPUT);
pinMode(41,OUTPUT);
pinMode(43,OUTPUT);
pinMode(45,OUTPUT);
pinMode(47,OUTPUT);
pinMode(49,OUTPUT);
pinMode(51,OUTPUT);
pinMode(53,OUTPUT);
   pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
      pinMode(7,OUTPUT);
       analogWrite(3,0);
       analogWrite(4,0);
       analogWrite(7,0);
digitalWrite(31,1);
digitalWrite(33,1);
digitalWrite(35,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(43,1);
digitalWrite(45,1);
digitalWrite(47,1);
digitalWrite(49,1);
digitalWrite(51,1);
digitalWrite(53,1);
digitalWrite(52,1);
digitalWrite(30,1);
digitalWrite(32,1);
digitalWrite(34,1);
digitalWrite(36,1);
digitalWrite(38,1);
digitalWrite(40,1);
digitalWrite(42,1);
digitalWrite(44,1);
digitalWrite(46,1);
digitalWrite(48,1);
digitalWrite(50,1);
digitalWrite(52,1);
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
   
  }
    //rtc.adjust(DateTime(2017, 8, 2,15, 56, 20));
}

void loop () {
    DateTime now = rtc.now();
    int hr = now.hour();
int mi = now.minute();
int sec = now.second();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(hr);
    Serial.print(':');
    Serial.print(mi);
    Serial.print(':');
    Serial.print(sec);
    Serial.println();
  if(hr < 22 & hr > 8){
    timecheck();
     for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 1) {
    analogWrite(3, fadeValue);
    analogWrite(4, fadeValue);
    delay(50);
  }
  for (int fadeValue = 200 ; fadeValue >= 0; fadeValue -= 1) {
    analogWrite(3, fadeValue);
    analogWrite(4, fadeValue);
    delay(50);
  }
  timecheck();
      for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 1) {
    analogWrite(4, fadeValue);
    analogWrite(7, fadeValue);
    delay(50);
  }
  for (int fadeValue = 200 ; fadeValue >= 0; fadeValue -= 1) {
    analogWrite(4, fadeValue);
    analogWrite(7, fadeValue);
    delay(50);
  }
  timecheck();

      for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 1) {
    analogWrite(7, fadeValue);
      delay(50);
  }
  for (int fadeValue = 200 ; fadeValue >= 0; fadeValue -= 1) {
    analogWrite(7, fadeValue);
    delay(50);
  }
  timecheck();
  
      for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 1) {
    analogWrite(4, fadeValue);
      delay(50);
  }
  for (int fadeValue = 200 ; fadeValue >= 0; fadeValue -= 1) {
    analogWrite(4, fadeValue);
    delay(50);
  }
  timecheck();
        for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 1) {
          analogWrite(3,fadeValue);
    analogWrite(4, fadeValue);
    analogWrite(7, fadeValue);
    delay(50);
  }
  for (int fadeValue = 200 ; fadeValue >= 0; fadeValue -= 1) {
     analogWrite(3,fadeValue);
    analogWrite(4, fadeValue);
    analogWrite(7, fadeValue);
    delay(50);
  }
  timecheck();
  }
  else {
    timecheck();
  analogWrite(3, 0);
    analogWrite(4, 0);
    analogWrite(7, 1);
    
  }
    
}
void timecheck(){
     DateTime now = rtc.now();
    int hr = now.hour();
int mi = now.minute();
int sec = now.second();
  if(hr ==0){
digitalWrite(53,0);
digitalWrite(51,0);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==12){
digitalWrite(53,0);
digitalWrite(51,0);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==1){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(31,1);
digitalWrite(33,1);
digitalWrite(35,0);
}
if(hr ==13){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(31,1);
digitalWrite(33,1);
digitalWrite(35,0);
}
if(hr ==2){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(31,1);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==14){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(31,1);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==3){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==15){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==16){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==4){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==17){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==5){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,1);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr==18){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==6){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,1);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr==19){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==7){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,1);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr==20){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==8){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,1);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==21){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==9){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,1);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==22){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==10){
digitalWrite(53,1);
digitalWrite(51,1);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==23){
digitalWrite(53,1);
digitalWrite(51,0);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==11){
digitalWrite(53,1);
digitalWrite(51,0);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==24){
digitalWrite(53,0);
digitalWrite(51,0);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(hr ==12){
digitalWrite(53,0);
digitalWrite(51,0);
digitalWrite(49,0);
digitalWrite(47,0);
digitalWrite(45,0);
digitalWrite(43,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(31,0);
digitalWrite(33,0);
digitalWrite(35,0);
}
if(mi >-1 & mi < 6){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,1);
digitalWrite(50,1);
digitalWrite(38,1);
digitalWrite(42,1);
digitalWrite(52,1);
digitalWrite(44,1);
digitalWrite(46,0);
}
if(mi >5 & mi < 11){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,1);
digitalWrite(50,1);
digitalWrite(38,1);
digitalWrite(42,1);
digitalWrite(52,1);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >10 & mi < 16){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,1);
digitalWrite(50,1);
digitalWrite(38,1);
digitalWrite(42,1);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >15 & mi < 21){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,1);
digitalWrite(50,1);
digitalWrite(38,1);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >20 & mi < 26){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,1);
digitalWrite(50,1);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >25 & mi < 31){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,1);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >30 & mi < 36){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,1);
digitalWrite(48,0);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >35 & mi < 41){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,1);
digitalWrite(40,0);
digitalWrite(48,0);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >40 & mi < 46){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,1);
digitalWrite(36,0);
digitalWrite(40,0);
digitalWrite(48,0);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >45 & mi < 51){
digitalWrite(30,1);
digitalWrite(34,1);
digitalWrite(32,0);
digitalWrite(36,0);
digitalWrite(40,0);
digitalWrite(48,0);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >50 & mi < 56){
digitalWrite(30,1);
digitalWrite(34,0);
digitalWrite(32,0);
digitalWrite(36,0);
digitalWrite(40,0);
digitalWrite(48,0);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
if(mi >55 & mi < 61){
digitalWrite(30,0);
digitalWrite(34,0);
digitalWrite(32,0);
digitalWrite(36,0);
digitalWrite(40,0);
digitalWrite(48,0);
digitalWrite(50,0);
digitalWrite(38,0);
digitalWrite(42,0);
digitalWrite(52,0);
digitalWrite(44,0);
digitalWrite(46,0);
}
}


