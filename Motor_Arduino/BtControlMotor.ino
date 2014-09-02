/* This is the source code of Arduino Leonardo. Leonardo is
the cpu of the car.Bluetooth serial module finishes the 
communication between the car and the controller, and L298N 
module drives the motor. */

#include <SoftwareSerial.h>
//feet for controlling L298N module
int IN1=9;
int IN2=8;
int IN3=7;
int IN4=6;
int ENA=10;
int ENB=5;
//serial port for bluetooth serial module
SoftwareSerial mySerial(11,12);
char val;

//define speed differential for turning actions
int lspeed0=10;
int lspeed1=127;
int rspeed0=10;
int rspeed1=127;

void mainInterface(){
  /* Some explaination of the actions. It will not appear
  in the controller windows, just for debugging. */
  
  mySerial.println("******** Welcome to bluetooth car control center ********");
  mySerial.println("f - Go foward straight");
  mySerial.println("b - Go back straight");
  mySerial.println("s - Stop");
  mySerial.println("r - Shift to right-turning mode");
  mySerial.println("l - Shift to left-turning mode");
  mySerial.println("c - Shift to straight mode");
  mySerial.println("a - Add speed");
  mySerial.println("d - Decrease speed");
  mySerial.println("***************************************************");
  mySerial.write('\n');
} 

void motorAction(int mode) {
  /* Based on different mode, Leonardo send control words to
  L298N */
  
  switch(mode) {
    case 1: {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    }
    case 0: {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    }
    case -1: {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    }
    case 2: {
      analogWrite(ENB, rspeed0);
      analogWrite(ENA, lspeed1);
      break;
    }
    case 3: {
      analogWrite(ENA, lspeed0);
      analogWrite(ENB, rspeed1);
      break;
    }
    case 4: {
      analogWrite(ENA, lspeed1);
      analogWrite(ENB, rspeed1);
      break;
    }
    case 5: {
      rspeed1=255;
      lspeed1=255;
      break;
    }
    case 6: {
      lspeed1=127;
      rspeed1=127;
      break;
    }
  }
}

void controlCenter() {
  /* Main control function. Once it is called, it reads the value
  from bluetooth module, then calls motorAction() for different
  situation. */
  
  val=mySerial.read();
  if(val=='a') {
    mySerial.write("add ");
    motorAction(5);
  }
  else if(val=='d') {
    mySerial.write("down ");
    motorAction(6);
  }
  if(val=='f') {
    mySerial.write("foward ");
    motorAction(1);
  }
  else if(val=='b') {
    mySerial.write("backward ");
    motorAction(-1);
  }
  else if(val=='s') {
    mySerial.write("stop ");
    motorAction(0);
  }
  else if(val=='r') {
    mySerial.write("right ");
    motorAction(2);
  }
  else if(val=='l') {
    mySerial.write("left ");
    motorAction(3);
  }
  else if(val=='c') {
    mySerial.write("center ");
    motorAction(4);
  }
}

void setup() {
  //set up the pins
  mySerial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENA, lspeed1);
  analogWrite(ENB, rspeed1);
}

void loop() {
  //main loop
  if(mySerial.available()>0) {
    mainInterface();
    while(1) controlCenter();
  }
}

