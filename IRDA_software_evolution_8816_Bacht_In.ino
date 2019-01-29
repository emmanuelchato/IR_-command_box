

#include <IRremote.h>

#define PIN_IR 3
IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(13, OUTPUT);


}

void loop() {

  /////////////////////////////////////////////////////////////////////////////Channel 77
  int sensor_power = digitalRead(A3);
  int khz = 38;
  if (sensor_power == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    //Channel 77
    
    irsend.sendNEC(0x202827D , 32);
    delay(1000);
    irsend.sendNEC(0x202827D , 32);
    delay(1000);
    irsend.sendNEC(0x202E01F , 32);
    delay(500);
    irsend.sendNEC(0x202E01F , 32);
    delay(500);
    //Channel 153
    //  irsend.sendNEC(0x202807F , 32);
    //delay(300);
    //irsend.sendNEC(0x202A05F , 32);
    //delay(300);
    //irsend.sendNEC(0x202C03F , 32);
    //delay(300);
  }
  /////////////////////////////////////////////////////////////////////////////Reset button section
  int sensor_reset  = digitalRead(A2);
  if (sensor_reset  == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);


    //Autodirection
    irsend.sendNEC(0x20202FD, 32);
    delay(1200);
    irsend.sendNEC(0x2028877, 32);
    delay(1200);
    // Reset Code
    irsend.sendNEC(0x202609F, 32);
    delay(500);
    irsend.sendNEC(0x202906F, 32);
    delay(500);
    irsend.sendNEC(0x20210EF, 32);
    delay(500);
    irsend.sendNEC(0x20200FF, 32);
    delay(500);
    irsend.sendNEC(0x202708F, 32);
    delay(1200);
    irsend.sendNEC(0x202708F, 32);
    delay(1200);
    irsend.sendNEC(0x202B04F, 32);
    delay(1200);
    irsend.sendNEC(0x20208F7, 32);
    delay(1200);
    irsend.sendNEC(0x202B04F, 32);
    delay(1200);





  }
  /////////////////////////////////////////////////////////////////////////////FW check
  int sensor_checkFW = digitalRead(A1);
  if (sensor_checkFW == LOW) {
    // Led command on & off
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    delay(250);
    irsend.sendNEC(0x202B04F, 32);
    delay(1000);
    //irsend.sendNEC(0x20220DF, 32);
    //delay(100);


  }

}
