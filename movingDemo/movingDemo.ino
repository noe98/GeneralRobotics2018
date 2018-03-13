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
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i < 1000; i++){
    moveForward(50);
  }
  for(int i=0; i < 1000; i++){
    moveBackward(50);
  }
}
