// Motor A
const int motorA = 9;
const int pwmA = 2;

// Motor B
const int motorB = 6;
const int pwmB = 1;

// IR sensor
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;
const int sensor4 = A3;
const int sensor5 = A4;
const int sensor6 = A5;

// Speed constant
const int normal = 130;
const int stopM = 0;
const int slow = 90;
const int fast = 220;

// Other constant
// const int dTime = ???
// const int bufffer = ???
// const int threshold = ???

void setup() {
  // set motor pin
  pinMode(pwmA, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(motorB, OUTPUT);
  
  // set IR sensor pin
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);

  // for serial communication
  Serial.begin(9600);

  //set motor to stop 
  //analogWrite(pwmA, 0);
  //analogWrite(pwmB, 0);
  //delay(2000);
  
}

void loop() {
  int s1 = analogRead(sensor1);
  int s2 = analogRead(sensor2);
  int s3 = analogRead(sensor3);
  int s4 = analogRead(sensor4);
  int s5 = analogRead(sensor5);
  int s6 = analogRead(sensor6);
  
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println("------ ");

  if(s1 == HIGH) {
    Serial.println("turn left");
    turnLeft(stopM, fast);
  }
  else if(s2 == HIGH) {
    Serial.println("turn left");
    turnLeft(slow, fast);
  }
  else if(s3 == HIGH) 
  {
    Serial.println("turn left");
    turnLeft(slow, normal);
  }
  else if(s6 == HIGH) {
   Serial.println("turn right");
   turnRight(fast, stopM);
  }
  else if(s5 == HIGH) {
   Serial.println("turn right");
   turnRight(fast, slow);
  }

  else if(s4 == HIGH) {
   Serial.println("turn right");
   turnRight(normal, slow);
  }
  
  // delay(dTime);
}

// speed1 < speed2
void turnRight(int speed1, int speed2) {
  digitalWrite(motorA, LOW);
  analogWrite(pwmA, speed1);
  digitalWrite(motorB, HIGH);
  analogWrite(pwmB, speed2);
}

// speed2 < speed1
void turnLeft(int speed1, int speed2) {
  digitalWrite(motorA, HIGH);
  analogWrite(pwmA, speed2);
  digitalWrite(motorB, LOW);
  analogWrite(pwmB, speed1);
}
