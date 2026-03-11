//-------------------------------------
//Code by Brayden Ford 
//-------------------------------------
//Welcome  To Centaurus's Code
//-------------------------------------

//library  for dual motor driver
#include <SparkFun_TB6612.h>

//library for remote
#include  <IRremote.h>

//ultra sonic sensor pins
int trigPin = 3;
int echoPin  = A2;
int pingTravelTime;

//remote
int IRpin = A0;
String Command;
IRrecv  IR(IRpin);
decode_results cmd;

//dual motor driver pins
#define AN1  12
#define BN1 7
#define AN2 4
#define BN2 8
#define PWMA 5
#define  PWMB 6
#define STBY 9

//constants for motor configuration
const int  offsetA = 1;
const int offsetB = -1;

//define duel motor driver pins
Motor  motor1 = Motor(AN1, AN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BN1, BN2,  PWMB, offsetB, STBY);

//delay
int dt = 100;

// Rnadom pattern for  turning function
long randomTurn = 43;

//Shift regigister pins for LEDs
const  int dataPin = A3;
const int clockPin = 13;
const int latchPin = 2;

//(LEDs)  when forward 
byte fLeds = 0b11111111;
//when slowed down
byte sLeds =  0b01111110;
//when slowed down more
byte ssLeds = 0b00111100;
//default  LEDs
byte dLeds = 0b01111110;
//when back
byte bLeds = 0b10000001;
//turn  LEDs off
byte oLeds = 0b00000000;

void setup() {
  //setup serial monitor
  Serial.begin(9600);

  //IR remote
  IR.enableIRIn();

  //ultra  sonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //shift register
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Rnadom pattern for turning to mimic AI features
  randomSeed(40);
  
}

void loop() {

  //wait until button has  been pressed
  while (IR.decode(&cmd) == 0) {

  }

  ////////////////////////////////if  IR = up arrow button - go forward
  if (cmd.value == 0xFF629D) {
    IR.enableIRIn();
    delay(60);
    IR.resume();
    forward(motor1, motor2, 255);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, bLeds);
    digitalWrite(latchPin,  HIGH);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST,  0b00000000);
    digitalWrite(latchPin, HIGH);
    delay(40);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00011000);
    digitalWrite(latchPin,  HIGH);
    delay(40);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b00100100);
    digitalWrite(latchPin, HIGH);
    delay(40);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b01000010);
    digitalWrite(latchPin, HIGH);
    delay(40);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b10000001);
    digitalWrite(latchPin,  HIGH);
    delay(40);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b11111111);
    digitalWrite(latchPin, HIGH);
  }
      else{
       if (cmd.value != 0xFF42BD) {
       IR.enableIRIn();
       delay(60);
       IR.resume();
       }
    }

  ////////////////////////////////if  IR = down arrow button - go back
  if (cmd.value == 0xFFA857) {
    IR.enableIRIn();
    delay(60);
    IR.resume();
    back(motor1, motor2, -160); 
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, bLeds);
    digitalWrite(latchPin,  HIGH);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST,  0b00000000);
    digitalWrite(latchPin, HIGH);
    delay(40);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b10000001);
    digitalWrite(latchPin,  HIGH);
    delay(40);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b01000010);
    digitalWrite(latchPin, HIGH);
    delay(40);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00100100);
    digitalWrite(latchPin, HIGH);
    delay(40);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00011000);
    digitalWrite(latchPin,  HIGH);
    delay(40);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b00000000);
    digitalWrite(latchPin, HIGH);
  }

  ////////////////////////////////if IR = left arrow button - turn left
  if  (cmd.value == 0xFF22DD) {
    IR.enableIRIn();
    delay(60);
    IR.resume();
    motor1.brake();
    motor2.drive(255);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
    digitalWrite(latchPin,  HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b10000000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b01000000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00100000);
    digitalWrite(latchPin,  HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b00010000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00001000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000100);
    digitalWrite(latchPin,  HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b00000010);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000001);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
    digitalWrite(latchPin,  HIGH);
    delay(20);
  }

  ////////////////////////////////if IR =  right arrow button - turn right
  if (cmd.value == 0xFFC23D) {
    IR.enableIRIn();
    delay(60);
    IR.resume();
    motor1.drive(255);
    motor2.brake();
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000001);
    digitalWrite(latchPin,  HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b00000010);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000100);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00001000);
    digitalWrite(latchPin,  HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b00010000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00100000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b01000000);
    digitalWrite(latchPin,  HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin,  clockPin, LSBFIRST, 0b10000000);
    digitalWrite(latchPin, HIGH);
    delay(20);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
    digitalWrite(latchPin, HIGH);
    delay(20);
  }

  ////////////////////////////////if  IR = OK button - stop
  if (cmd.value == 0xFF02FD) {
    IR.enableIRIn();
    delay(60);
    IR.resume();
    forward(motor1, motor2, 0);
    digitalWrite(latchPin,  LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, fLeds);
    digitalWrite(latchPin,  HIGH);
  }

  ////////////////////////////////////IR = # (number sign button)
  if (cmd.value == 0xFF52AD) {
    IR.enableIRIn();
    delay(10);
    IR.resume();
    //turn on each LED
    for (int i = 0; i < 256; i++) {
      //take the  latchClock low so the LEDs don't
      //change while you're sending in bits
      digitalWrite(latchPin, LOW);
      //shift out the bits
      shiftOut(dataPin,  clockPin, MSBFIRST, i);
      digitalWrite(latchPin, HIGH);
      delay(60);
      //wait until button has been pressed
      while (IR.decode(&cmd) == 0)  {
        if (cmd.value == 0xFF52AD) {
          for (int i = 0; i < 256;  i++) {
            //take the latchClock low so the LEDs don't
            //change  while you're sending in bits
            digitalWrite(latchPin, LOW);
            //shift  out the bits
            shiftOut(dataPin, clockPin, MSBFIRST, i);
            digitalWrite(latchPin,  HIGH);
            delay(60);
          }
        }
      }
    }
  }
      ////////////////////////////////////if IR = * (star button)
  if  (cmd.value == 0xFF42BD) {
    AI_driving();

  }
}

  void AI_driving(){
  
    //initialize and print vision distance of Centaurus
    Serial.print("  ");
    Serial.print("Distance of View is: ");
    Serial.println(pingTravelTime);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin,  HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pingTravelTime  = pulseIn(echoPin, HIGH);
    delay(100);

    //forward
    if (pingTravelTime  > 3000) {
      forward(motor1, motor2, 255);
      digitalWrite(latchPin,  LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, fLeds);
      digitalWrite(latchPin,  HIGH);
    }

    //slow down
    if (pingTravelTime < 3000 && pingTravelTime  > 2500) {
      forward(motor1, motor2, 200);
      digitalWrite(latchPin,  LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, sLeds);
      digitalWrite(latchPin,  HIGH);
    }

    //slow down more
    if (pingTravelTime < 2500 &&  pingTravelTime > 2000) {
      forward(motor1, motor2, 160);
      digitalWrite(latchPin,  LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, ssLeds);
      digitalWrite(latchPin,  HIGH);
    }

    //back
    if (pingTravelTime < 600 && pingTravelTime  >= 0) {
      back(motor1, motor2, -180);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, bLeds);
      digitalWrite(latchPin,  HIGH);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin,  LSBFIRST, 0b00000000);
      digitalWrite(latchPin, HIGH);
      delay(140);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST,  0b10000001);
      digitalWrite(latchPin, HIGH);
      delay(140);
      digitalWrite(latchPin,  LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, 0b01000010);
      digitalWrite(latchPin,  HIGH);
      delay(140);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin,  clockPin, LSBFIRST, 0b00100100);
      digitalWrite(latchPin, HIGH);
      delay(140);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST,  0b00011000);
      digitalWrite(latchPin, HIGH);
      delay(140);
      digitalWrite(latchPin,  LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
      digitalWrite(latchPin,  HIGH);
      delay(140);
    }

    //turn (random direction)
    if  (pingTravelTime > 600 && pingTravelTime < 2200) {
      //generate and print  decesion thought process system
      randomTurn = random(2);
      Serial.print("  randomTurn Value is: ");
      Serial.print(randomTurn);
      if (randomTurn  == 1) {
        motor1.drive(200);
        motor2.brake();
        digitalWrite(latchPin,  LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
        digitalWrite(latchPin,  HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin,  clockPin, LSBFIRST, 0b00000001);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000010);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000100);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00001000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00010000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00100000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b01000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b10000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
      }
      if (randomTurn == 0) {
        motor1.brake();
        motor2.drive(200);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b10000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b01000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00100000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00010000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00001000);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000100);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000010);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000001);
        digitalWrite(latchPin, HIGH);
        delay(80);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST,  0b00000000);
        digitalWrite(latchPin, HIGH);
        delay(80);
      }
    }
    //forward
    if(pingTravelTime < 0) {
      forward(motor1,  motor2, 255);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin,  LSBFIRST, fLeds);
      digitalWrite(latchPin, HIGH);
    }

  }

//------------------------------------------------------------------------
//Thanks  for visiting the code of Centaurus. Hope you find this useful!
//------------------------------------------------------------------------
