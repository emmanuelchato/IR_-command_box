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
  unsigned int  source[67] = {4500,4450, 600,1650, 600,1650, 550,1650, 600,500, 600,550, 550,550, 600,500, 600,550, 550,1650, 600,1650, 550,1650, 600,500, 600,550, 550,550, 600,500, 600,550, 550,1650, 600,550, 600,500, 550,550, 600,500, 600,550, 550,550, 600,500, 600,550, 550,1650, 600,1650, 550,1650, 600,1650, 550,1650, 600,1650, 550,1700, 550};  // SAMSUNG E0E0807F
  unsigned int  arriba[67] = {4500,4450, 600,1650, 550,1650, 600,1650, 600,500, 600,500, 600,550, 550,550, 600,500, 600,1650, 550,1650, 600,1650, 600,500, 600,550, 550,550, 550,550, 600,500, 600,550, 550,550, 600,500, 600,550, 550,550, 550,1650, 600,1650, 600,500, 600,1650, 550,1650, 600,1650, 600,1600, 600,1650, 600,500, 600,550, 550,1650, 600};  // SAMSUNG E0E006F9


  if (sensor_power == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

   //Restart 
   irsend.sendRaw(source,67, 32);
   delay(500);
   irsend.sendRaw(arriba,67, 32);
   delay(500);
  }
  /////////////////////////////////////////////////////////////////////////////A/V test section
  int sensor_technicalt = digitalRead(A1);
  int StartVol = 0;
  int EndVol = 23;
  int Start_dummy = 0;
  int End_dummy = 10;
  int Start_input = 0;
  int End_input = 2;
 // unsigned int  source[67] = {4500,4450, 600,1650, 600,1650, 550,1650, 600,500, 600,550, 550,550, 600,500, 600,550, 550,1650, 600,1650, 550,1650, 600,500, 600,550, 550,550, 600,500, 600,550, 550,1650, 600,550, 600,500, 550,550, 600,500, 600,550, 550,550, 600,500, 600,550, 550,1650, 600,1650, 550,1650, 600,1650, 550,1650, 600,1650, 550,1700, 550};  // SAMSUNG E0E0807F
  unsigned int  bajo[67] = {4500,4450, 600,1650, 600,1600, 600,1650, 600,500, 600,550, 550,550, 550,550, 600,500, 600,1650, 600,1600, 600,1650, 600,500, 600,550, 550,550, 550,550, 600,550, 550,1650, 600,500, 600,550, 550,550, 550,550, 600,1650, 550,1650, 600,550, 550,550, 550,1650, 600,1650, 600,1650, 550,1650, 600,500, 600,550, 550,1650, 600};  // SAMSUNG E0E08679

  if (sensor_technicalt == LOW) {
    //Led command on & off
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    while (StartVol <= EndVol) {
      irsend.sendNEC(0x202A857 , 32);
      delay(100);
      StartVol++;
    }
    //irsend.sendNEC(0x202E01F , 32);
    //delay(300);
    //irsend.sendNEC(0x202E01F , 32);
    //delay(50);
  /////////////////////////////////////////////////////////////////////////////TV control section  
  ////////////////////////////////////Start Dummy Section/////////////////////

      while (Start_dummy <= End_dummy) {
      irsend.sendNEC(0x20DF10EF, 32);
      delay(1000);
      Start_dummy++;
    }
  ////////////////////////////////////End Dummy Section/////////////////////
    irsend.sendSony (0xA50, 12);
    delay(40);
    irsend.sendSony (0xA50, 12);
    delay(40);
    irsend.sendSony (0xA50, 12);
    delay(40);
    irsend.sendNEC(0x20DF10EF, 32);
    delay(2500);
   
   irsend.sendRaw(source,67, 32);
    delay(500);
   irsend.sendRaw(bajo,67, 32);
   delay(500);
 
    irsend.sendNEC(0x20202FD, 32);
    delay(1400);
    irsend.sendNEC(0x20220DF, 32);
    delay(500);
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
    irsend.sendNEC(0x202827D, 32);
    delay(500);
    irsend.sendNEC(0x202827D, 32);
    delay(500);

    irsend.sendNEC(0x20202FD, 32);
    delay(500);
    irsend.sendNEC(0x202708F, 32);
    delay(100);
    irsend.sendNEC(0x202708F, 32);
    delay(100);
    //reset code
    irsend.sendNEC(0x202609F, 32);
    delay(100);
    irsend.sendNEC(0x202906F, 32);
    delay(100);
    irsend.sendNEC(0x20210EF, 32);
    delay(100);
    irsend.sendNEC(0x20200FF, 32);
    delay(100);
    //Autodirection reset
    irsend.sendNEC(0x202708F, 32);
    delay(100);
    irsend.sendNEC(0x202708F, 32);
    delay(100);
    irsend.sendNEC(0x202B04F, 32);
    delay(100);
    irsend.sendNEC(0x202B04F, 32);
    delay(100);
    irsend.sendNEC(0x20208F7, 32);
    delay(100);
    irsend.sendNEC(0x202B04F, 32);
    delay(100);
  }
}

