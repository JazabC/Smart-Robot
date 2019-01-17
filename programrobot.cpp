




/*
R = self.robot_wheel_radius
L = self.robot_wheel_base_length
prev_x, prev_y, prev_theta = self.estimated_pose.scalar_unpack()
new_x = prev_x + ( d_center * cos( prev_theta ) )
new_y = prev_y + ( d_center * sin( prev_theta ) )
new_theta = prev_theta + ( ( d_right_wheel - d_left_wheel ) / self.robot_wheel_base_length )
*/

const int LeftmPin1 = 7;
const int LeftmPin2 = 6;
const int RightmPin3 = 10;
const int RightmPin4 = 9;
#define echoPi 8
#define trigPi 9
#define ledPi 15

#define echoPLeft 2
#define trigPLeft 3

#define echoPRight 5
#define trigPRight 4

int maximumRange = 36;
int minimumRange = 11;
long durationFront, distanceFront;
long durationLeft, distanceLeft;
long durationRight, distanceRight;

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

  pinMode(trigPinLeft, OUTPUT);
 pinMode(echoPinLeft, INPUT);

  pinMode(trigPinRight, OUTPUT);
 pinMode(echoPinRight, INPUT);

 pinMode(LEDPin, OUTPUT);
}

void loop() {

 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);
 durationFront = pulseIn(echoPin, HIGH);


 distanceFront = (durationFront/2) / 29.1;





  digitalWrite(trigPinLeft, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPinLeft, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPinLeft, LOW);
 durationLeft = pulseIn(echoPinLeft, HIGH);


 distanceLeft = (durationLeft/2) / 29.1;



  digitalWrite(trigPinRight, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPinRight, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPinRight, LOW);
 durationRight = pulseIn(echoPinRight, HIGH);

 distanceRight = (durationRight/2) / 29.1;




 if (distanceFront > 40) {
  analogWrite(LeftmotorPin1, 0);
  analogWrite(LeftmotorPin2, 177);
  analogWrite(RightmotorPin3, 0);
  analogWrite(RightmotorPin4, 255);
 }


 else if (distanceFront < 40 && distanceRight > distanceLeft){
  analogWrite(LeftmotorPin1, 0);
  analogWrite(LeftmotorPin2, 255);
  analogWrite(RightmotorPin3, 0);
  analogWrite(RightmotorPin4, 0);
 }

 else if (distanceFront < 40 && distanceRight < distanceLeft){
  analogWrite(LeftmotorPin1,0 );
  analogWrite(LeftmotorPin2,0 );
  analogWrite(RightmotorPin3,0 );
  analogWrite(RightmotorPin4, 255);
 }

 else if (distanceFront < 40 && distanceLeft == distanceRight) {
  analogWrite(LeftmotorPin1, 0);
  analogWrite(LeftmotorPin2, 255);
  analogWrite(RightmotorPin3, 0);
  analogWrite(RightmotorPin4, 0);
 }

 delay(36);
}
