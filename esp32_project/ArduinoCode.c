// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLWpNwHeAp"
#define BLYNK_DEVICE_NAME "Final Blink"

#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_TTGO_T_OI
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT

#define PIN_SERVO  16

#include <Arduino.h> 
#include <ESP32Servo.h>
#include <string.h>
#include "DHTesp.h"
#include "BlynkEdgent.h"

DHTesp dht;
int T, H;

BlynkTimer timer;

int condition = 0;
Servo myServo;

char userInput;

void myTimer(){
  TempAndHumidity data = dht.getTempAndHumidity();
  T = data.temperature;
  H = data.humidity;
  Blynk.virtualWrite(V0, T);
  Blynk.virtualWrite(V1, H);
}

void control(int condition){
  if(condition==1){
     for(int pos = 0; pos < 360; pos += 1) { 
        myservo.write(pos);
        delay(50);  
      }
  }
  if(condition==2){
     for(int pos = 0; pos < 360; pos += 2) { 
        myservo.write(pos);
        delay(50);  
      }
  }
  if(condition==3){
     for(int pos = 0; pos < 360; pos += 5) { 
        myservo.write(pos);
        delay(50);  
      }
  }
  if(condition==4){
     for(int pos = 0; pos < 360; pos += 7) { 
        myservo.write(pos);
        delay(50);  
      }
  }
}

void setup() {
  // put your setup code here, to run once:
  dht.setup(11, DHTesp::AM2302);
  delay(100);

  BlynkEdgent.begin();
  timer.setInterval(100L, myTimer);

  Serial.begin(115200);
  myServo.attach(PIN_SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
// python code 辨識人數
  userInput = Serial.read();
  //Serial.println(userInput);
  /*if (userInput == '1') Serial.println('open1');
  else if(userInput == '2') Serial.println('open2');*/

// 型別轉換
  String a = String(userInput);
  int pos = a.toInt();

// 感測器資料分析
  if (T>=25 || pos==1) condition = 1;
  else if(T>=26 || pos==4) condition = 2;
  else if (T>=27 || H>=60 || pos == 6) condition = 3;
  else condition = 4;

//控制模擬風扇階段
  control(condition);

  }
  BlynkEdgent.run();
  timer.run();
}