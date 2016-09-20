// Motor A
//const int motorA = 9;
//const int pwmA = 2;

// Motor B
//const int motorB = 6;
//const int pwmB = 1;

// IR sensor
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A0;
const int sensor4 = A1;
const int sensor5 = A0;
const int sensor6 = A1;

int s1;

void setup() {
  // set motor pin
  //pinMode(pwmA, OUTPUT);
  //pinMode(motorA, OUTPUT);
  //pinMode(pwmB, OUTPUT);
  //pinMode(motorB, OUTPUT);

  // for serial communication
  Serial.begin(9600);

  //set motor to stop 
  //analogWrite(pwmA, 0);
  //analogWrite(pwmB, 0);
  //delay(2000);
  
}

void loop() {
  s1 = analogRead(sensor1);
  //int s2 = analogRead(sensor2);
  //int s3 = analogRead(sensor3);
  //int s4 = analogRead(sensor4);
  //int s5 = analogRead(sensor5);
  //int s6 = analogRead(sensor6);

  if(s1 != 0) {
    Serial.println(s1);
  //Serial.println(s2);
  //Serial.println(s3);
  //Serial.println(s4);
  //Serial.println(s5);
  //Serial.println(s6);
  
      if(s1 >= 80) 
  {
   Serial.println("turn left");
    //turnLeft();
  }

  if(s1 <= 20) 
  {
    Serial.println("turn right");
    //turnRight();
  }

  Serial.println("------ ");
  delay(500);
    }
}

//void turnRight() {
//  digitalWrite(motorA, LOW);
//  analogWrite(pwmA, 90);
//  digitalWrite(motorB, HIGH);
//  analogWrite(pwmB, 130);
//}

//void turnLeft() {
//  digitalWrite(motorA, HIGH);
//  analogWrite(pwmA, 130);
//  digitalWrite(motorB, LOW);
//  analogWrite(pwmB, 90);
//}

