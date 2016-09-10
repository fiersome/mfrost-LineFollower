// Motor A
const int motorA = 9;
const int pwmA = 2;

// Motor B
const int motorB = 6;
const int pwmB = 1;

// IR sensor
const int sensor1 = A0;
const int sensor2 = A1;

void setup() {
  // set motor pin
  pinMode(pwmA, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(motorB, OUTPUT);
  
  // set IR sensor pin
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  // for serial communication
  Serial.begin(9600);

  //set motor to stop 
  //analogWrite(pwmA, 0);
  //analogWrite(pwmB, 0);
  //delay(2000);
  
}

void loop() {
  float s1 = digitalRead(sensor1);
  float s2 = digitalRead(sensor2);
  
  Serial.print(s1 );
  Serial.print("------ ");
  Serial.println(s2);
  
  if(s1 == HIGH && s2 == LOW) 
  {
    Serial.println("turn left");
    turnLeft();
  }

  if(s2 == HIGH && s1 == LOW) 
  {
    Serial.println("turn right");
    turnRight();
  }

}

void turnRight() {
  digitalWrite(motorA, LOW);
  analogWrite(pwmA, 90);
  digitalWrite(motorB, HIGH);
  analogWrite(pwmB, 130);
}

void turnLeft() {
  digitalWrite(motorA, HIGH);
  analogWrite(pwmA, 130);
  digitalWrite(motorB, LOW);
  analogWrite(pwmB, 90);
}

