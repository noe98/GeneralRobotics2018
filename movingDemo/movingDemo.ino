void setup() {
  // put your setup code here, to run once:
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void moveForward(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void moveBackwards(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void moveLeft(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // turn off motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void moveRight(int speed){
  moveStop();
  
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // turn off motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // set speed within a possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void moveStop(){
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(200);
}
void loop() {
  // put your main code here, to run repeatedly:

}
