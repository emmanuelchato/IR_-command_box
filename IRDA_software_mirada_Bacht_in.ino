

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

  /////////////////////////////////////////////////////////////////////////////Power button section
  int sensor_power = digitalRead(A1);
  int Starchan_seq = 0;
  int Endchan_seq = 15;

  if (sensor_power == LOW) {

    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    while (Starchan_seq <= Endchan_seq)
    {
      irsend.sendRC5(0x854, 12);
      delay(3000);
      Starchan_seq++;
    }

    irsend.sendRC5(0x854, 12);
    delay(3000);
    irsend.sendRC5(0x85C, 12);
    delay(3000);
    irsend.sendRC5(0x841 , 12);
    delay(400);
    irsend.sendRC5(0x845 , 12);
    delay(400);
    irsend.sendRC5(0x843 , 12);
    delay(400);
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
      delay(2000);
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

  /////////////////////////////////////////////////////////////////////////////Channel map loading
  int sensor_channeload = digitalRead(A3);
  int Startauth_seq = 0;
  int Endauth_seq = 2;
  if (sensor_channeload == LOW) {

    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    //Channel map load sequence
    irsend.sendRC5(0x86F  , 12);
    delay(700);

    //Service code
    irsend.sendRC5(0x46  , 12);
    delay(150);
    irsend.sendRC5(0x49  , 12);
    delay(150);
    irsend.sendRC5(0x48  , 12);
    delay(150);
    irsend.sendRC5(0x40  , 12);
    delay(150);
    irsend.sendRC5(0x854, 12);
    delay(8000);
    //Initial configuration
    while (Startauth_seq <= Endauth_seq)
    {
      irsend.sendRC5(0x854, 12);
      delay(3000);
      Startauth_seq++;
    }
  }
}






