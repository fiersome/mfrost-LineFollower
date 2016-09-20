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

int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
int counter1 = 0;

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
     if(counter1 == 20) {
          s1 = s1 / counter1;
          Serial.println(s1);
          //Serial.println(s2);
          //Serial.println(s3);
          //Serial.println(s4);
          //Serial.println(s5);
          //Serial.println(s6);
  
          followLine(checkInput());

          Serial.println("------ ");
          counter1 = 0;
          delay(500);
    }
    else {
       int mean1 = analogRead(sensor1);
       if(mean1 != 0) {
          s1 = s1 + mean1;
          counter1++;
        }
       //int s2 = analogRead(sensor2);
       //int s3 = analogRead(sensor3);
       //int s4 = analogRead(sensor4);
       //int s5 = analogRead(sensor5);
       //int s6 = analogRead(sensor6);
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

int checkInput() {
    int input = B000000;
    if(s6 < 65) {
      input += B000000;
    }
    else {
      input += B000001;
    }
    if(s5 < 60) {
      input += B000000;
    }
    else {
      input += B000010;
    }
    if(s4 < 50) {
      input += B000000;
    }
    else {
      input += B000100;
    }
    if(s3 < 15) {
      input += B000000;
    }
    else {
      input += B001000;
    }
    if(s2 < 25) {
      input += B000000;
    }
    else {
      input += B010000;
    }
    if(s1 < 25) {
      input += B000000;
    }
    else {
      input += B100000;
    }
    return input;
  }

void followLine(int input) {
    if(input == B110011 || input == B000000 || input == B100001 || input == 0b000001 || input == 0b100000) {
      Serial.println("maju");
    }
    else if (input == B110111 || input == B101111 || input == B100111) {
      Serial.println("belok kiri");
    }

    else if(input == B011111 || input == B001111 || input == B000111) {
      Serial.println("belok kiri 90 derajat");
    }

    else if(input == B111011 || input ==  B111101 || input == B111001) {
      Serial.println("belok kanan");
    }

    else if(input == B111110 || input == B111100 || input == B111000) {
      Serial.println("belok kanan 90 derajat");
    }
    else if(input == B111111) {
      Serial.println("berhenti");
    }
  }

