#include <IRremote.h>

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

  /////////////////////////////////////////////////////////////////////////////Restart routine
  int sensor_power = digitalRead(A3);
  int Start_inputrest = 0;
  int End_inputrest = 2;
  unsigned int  source[67] = {4500, 4450, 600, 1650, 600, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 600, 500, 600, 550, 550, 1650, 600, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 600, 500, 600, 550, 550, 1650, 600, 550, 600, 500, 550, 550, 600, 500, 600, 550, 550, 550, 600, 500, 600, 550, 550, 1650, 600, 1650, 550, 1650, 600, 1650, 550, 1650, 600, 1650, 550, 1700, 550}; // SAMSUNG E0E0807F
  unsigned int  volmas[19] = {850, 850, 1750, 850, 900, 850, 850, 850, 900, 850, 850, 1750, 1750, 1700, 1750, 1750, 1750, 1700, 900};
  unsigned int  derecha[21] = {850,850, 900,850, 1750,850, 850,850, 900,850, 850,1750, 1750,1750, 1700,850, 900,1700, 900,850, 850};
                          

  if (sensor_power == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    //Restart
    irsend.sendRaw(source, 67, 32);
    delay(1000);
    irsend.sendRaw(source, 67, 32);
    delay(1000);

  }
  /////////////////////////////////////////////////////////////////////////////A/V test section
  int sensor_technicalt = digitalRead(A1);
  int StartVol = 0;
  int EndVol = 70;
  int Start_dummy_hdmi = 0;
  int End_dummy_hdmi = 15;
  int Start_dummy_AV = 0;
  int End_dummy_AV = 15;
  int ST_FW_direction = 0;
  int EndFW_direction = 2;
  int ST_FW_direction2 = 0;
  int EndFW_direction2 = 1;
  int Start_dummy_FW = 0;
  int End_dummy_FW = 10;


  if (sensor_technicalt == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    while (StartVol <= EndVol) {
      irsend.sendRaw(volmas, 19, 32);
      delay(100);
      StartVol++;
    }
    ////////////////////////////////////Start Dummy Section HMDI/////////////////////
    while (Start_dummy_hdmi <= End_dummy_hdmi) {
      irsend.sendNEC(0x20DF10EF, 32);
      delay(1000);
      Start_dummy_hdmi++;
    }
    ////////////////////////////////////End Dummy Section HDMI/////////////////////

    irsend.sendRaw(source, 67, 32);
    delay(500);
    irsend.sendRaw(source, 67, 32);
    delay(500);

    ////////////////////////////////////Start Dummy Section AV/////////////////////
    while (Start_dummy_AV <= End_dummy_AV) {
      irsend.sendNEC(0x20DF10EF, 32);
      delay(1000);
      Start_dummy_AV++;
    }
    ////////////////////////////////////End Dummy Section AV/////////////////////

    irsend.sendRaw(source, 67, 32);
    delay(500);
    irsend.sendRaw(source, 67, 32);
    delay(500);

    ////////////////////////////////////Verification sequence/////////////////////

    irsend.sendRC5(0x85B  , 12);
    delay(1000);

    ////////////////////////////////////Menu direction/////////////////////
    while (ST_FW_direction <= EndFW_direction)
    {
      irsend.sendRC5(0x51, 12);
      delay(1100);
      ST_FW_direction++;
    }
    irsend.sendRC5(0x854, 12);
    delay(1000);
    irsend.sendRC5(0x51, 12);
    delay(1000);
    irsend.sendRC5(0x854, 12);
    delay(1000);
   

    ////////////////////////////////////Start Dummy Section FW/////////////////////
    while (Start_dummy_FW <= End_dummy_FW) {
      irsend.sendNEC(0x20DF10EF, 32);
      delay(1000);
      Start_dummy_FW++;
    }
    ////////////////////////////////////End Dummy Section FW/////////////////////



    
    while (ST_FW_direction2 <= EndFW_direction2) {
      irsend.sendRaw(derecha,21, 12);
      delay(1000);
      ST_FW_direction2++;
    }
  }

    /////////////////////////////////////////////////////////////////////////////Reset button section
    int sensor_reset = digitalRead(A2);
    int StartReset_direction = 0;
    int EndReset_direction = 2;
    int StartReset_code = 0;
    int EndReset_code = 3;
    if (sensor_reset == LOW) {

      //Led command on & off
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);

      //Reset sequence
      irsend.sendRC5(0x85B  , 12);
      delay(1000);

      //Menu direction

      while (StartReset_direction <= EndReset_direction)
      {
        irsend.sendRC5(0x51, 12);
        delay(800);
        StartReset_direction++;
      }
      irsend.sendRC5(0x854  , 12);
      delay(1000);
      irsend.sendRC5(0x86F  , 12);
      delay(150);

      //Menu code & OK

      while (StartReset_code <= EndReset_code)
      {
        irsend.sendRC5(0x46, 12);
        delay(150);
        StartReset_code++;
      }
      irsend.sendRC5(0x854  , 12);
      delay(150);
    }
  }




