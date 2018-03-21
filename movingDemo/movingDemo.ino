/*
 * Washington and Lee University General Robotics Team 2018.
 * Use intended for the OSU Mercury Challenge.
 * Code adapted from https://www.youtube.com/watch?v=BqYcmBRYGWQ 
 */

//Motor A [Front Right]
int enA = 10;
int in1 = 9;
int in2 = 8;
//Motor B [Front Left]
int enB = 5;
int in3 = 7;
int in4 = 6;
//Motor C [Back Right]
int enC = 15;
int in5 = 14;
int in6 = 13;
//Motor D [Back Left]
int enD = 20;
int in7 = 19;
int in8 = 18;

//Joystick ish my dude
int UD = 0;
int LR = 0;
/* Arduino Micro output pins*/
int DWN = 33; 
int UP = 32;
int LT = 31;
int RT = 30;
/* Arduino Micro Input Pins */
int IUP=A0;
int ILR=A1;

int MID = 10; // 10 mid point delta arduino, use 4 for attiny
int LRMID = 0;
int UPMID = 0;

void setup() {
  // put your setup code here, to run once:
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT); //Engine A
  pinMode(enB, OUTPUT); //Engine B
  pinMode(enC, OUTPUT); //Engine C
  pinMode(enD, OUTPUT); //Engine D
  pinMode(in1, OUTPUT); //A
  pinMode(in2, OUTPUT); //A
  pinMode(in3, OUTPUT); //B
  pinMode(in4, OUTPUT); //B
  pinMode(in5, OUTPUT); //C
  pinMode(in6, OUTPUT); //C
  pinMode(in7, OUTPUT); //D
  pinMode(in8, OUTPUT); //D

  pinMode(DWN, OUTPUT); //Down
  pinMode(UP, OUTPUT);  //Up
  pinMode(LT, OUTPUT);  //Left
  pinMode(RT, OUTPUT);  //Right

  digitalWrite(DWN, HIGH); //D
  digitalWrite(UP, HIGH);  //U
  digitalWrite(LT, HIGH);  //L
  digitalWrite(RT, HIGH);  //R

  //calabrate center
  LRMID = analogRead(ILR); //Horizontal
  UPMID = analogRead(IUP); //Vertical
}

void loop() {
  UD = analogRead(IUP);
  LR = analogRead(ILR);
  // UP-DOWN
  if(UD < UPMID - MID){
   digitalWrite(DWN, LOW);
   moveInput();
  }else{
   digitalWrite(DWN, HIGH);
  }
  
  if(UD > UPMID + MID){
   digitalWrite(UP, LOW);
   moveInput();
  }else{
   digitalWrite(UP, HIGH);
  }
  // LEFT-RIGHT
  if(LR < LRMID - MID){
   digitalWrite(LT, LOW);
   moveInput();
  }else{
   digitalWrite(LT, HIGH);
  }
  
  if(LR > LRMID + MID){
   digitalWrite(RT, LOW);
   moveInput();
  }else{
   digitalWrite(RT, HIGH);
  }
}

void moveInput(){
  if(RT == LOW){
    moveRight(50);
  }
  if(LT == LOW){
    moveLeft(50);
  }
  if(UP == LOW){
    moveForward(50);
  }
  if(DWN == LOW){
    moveBackwards(50);
  }
}
void moveForward(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // turn on motor C
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);

  // turn on motor D
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  analogWrite(enC, speed);
  analogWrite(enD, speed);
}

void moveBackwards(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // turn on motor C
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);

  // turn on motor D
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  analogWrite(enC, speed);
  analogWrite(enD, speed);
}

void moveLeft(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // turn off motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // turn on motor C
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);

  // turn on motor D
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  analogWrite(enC, speed);
  analogWrite(enD, speed);
}

void moveRight(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // turn off motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // turn on motor C
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);

  // turn on motor D
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  analogWrite(enC, speed);
  analogWrite(enD, speed);
}

void moveStop(){
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);  
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);

  delay(200);
}
