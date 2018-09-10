

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

  /////////////////////////////////////////////////////////////////////////////Channel 77 & transparency button section
  int sensor_power = digitalRead(A3);
  int Startseqt_ok = 0;
  int Endseqt_ok = 2;
  int Startseqt2_ok = 0;
  int Endseqt2_ok = 2;
  if (sensor_power == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    //Power on command
    irsend.sendNEC(0x20202FD, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);
    while (Startseqt_ok <= Endseqt_ok) {
    irsend.sendNEC(0x202708F, 32);
    delay(300);
    Startseqt_ok++;
    }
    irsend.sendNEC(0x202B04F, 32);
    delay(300);
    irsend.sendNEC(0x202708F, 32);
    delay(300);
    irsend.sendNEC(0x202708F, 32);
    delay(300);
    irsend.sendNEC(0x202B04F, 32);
    delay(300);
    irsend.sendNEC(0x202B04F, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);
    while (Startseqt2_ok <= Endseqt2_ok) {
    irsend.sendNEC(0x202708F, 32);
    delay(300);
    Startseqt2_ok++;
    }
    irsend.sendNEC(0x202827D, 32);
    delay(300);
    irsend.sendNEC(0x202E01F , 32);
    delay(400);
    irsend.sendNEC(0x202E01F , 32);
    delay(400);

  }
  /////////////////////////////////////////////////////////////////////////////Reset button section
  int sensor_reset  = digitalRead(A2);
  int Startseqr_ok = 0;
  int Endseqr_ok = 4;
  int Startseqr2_ok = 0;
  int Endseqr3_ok = 1;
  int Startseqr3_ok = 0;
  int Endseqr2_ok = 3;
  if (sensor_reset  == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    //Menu option
    irsend.sendNEC(0x20202FD, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);

    while (Startseqr_ok <= Endseqr_ok) {
      irsend.sendNEC(0x202708F, 32);
      delay(300);
      Startseqr_ok++;
    }
    irsend.sendNEC(0x202B04F, 32);
    delay(300);

    //reset code
    irsend.sendNEC(0x202609F, 32);
    delay(300);
    irsend.sendNEC(0x202906F, 32);
    delay(300);
    irsend.sendNEC(0x20210EF, 32);
    delay(300);
    irsend.sendNEC(0x20200FF, 32);
    delay(300);

    while (Startseqr2_ok <= Endseqr2_ok) {
      irsend.sendNEC(0x202708F, 32);
      delay(300);
      Startseqr2_ok++;
    }
    irsend.sendNEC(0x202B04F, 32);
    delay(300);
    while (Startseqr3_ok <= Endseqr3_ok) {
      irsend.sendNEC(0x202708F, 32);
      delay(300);
      Startseqr3_ok++;
    }
    irsend.sendNEC(0x202B04F, 32);
    delay(300);
    irsend.sendNEC(0x20208F7, 32);
    delay(300);
    irsend.sendNEC(0x202B04F, 32);
    delay(300);

  }
  /////////////////////////////////////////////////////////////////////////////Vout
  int sensor_checkFW = digitalRead(A1);
  int StarFW_seq = 0;
  int EndFW_seq = 2;
  if (sensor_checkFW == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    irsend.sendNEC(0x20224DB, 32);
    delay(100);
  }
}

