int la = 2;
int lb = 3;
int ra = 4;
int rb = 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int aspeed = analogRead(A0) - 500;
  int bspeed = analogRead(A1) - 531;
  if (abs(aspeed) < 5){aspeed = 0;}
  if (abs(bspeed) < 5){bspeed = 0;}
  aspeed = map(aspeed, -420, 420, -100, 100);
  bspeed = map(bspeed, -420, 420, -100, 100);
  int left = (aspeed + bspeed);
  int right = (aspeed - bspeed);
  left = constrain(left, -200,200);
  right = constrain(right, -200,200);

  if((left != 0) and (right != 0)){
    analogWrite(la, 120 + left);
    analogWrite(lb, 120 - left);
    analogWrite(ra, 120 + right);
    analogWrite(rb, 120 - right);
  }
  else{
    analogWrite(la, 0);
    analogWrite(lb, 0);
    analogWrite(ra, 0);
    analogWrite(rb, 0);
  }
  

  Serial.print(left);
  Serial.print(", ");
  Serial.println(right);
  

}

