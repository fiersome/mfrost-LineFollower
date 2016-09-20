// Motor A
//const int motorKiriA = 3;
//const int motorKananB = 4;
//const int enKiri = 

// Motor B
//const int motorKananA = 0;
//const int motorKananB = 1;
//const int enKanan = 

// IR sensor
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;
const int sensor4 = A3;
const int sensor5 = A4;
const int sensor6 = A5;

// other variable
const int batas = 25;

int state1 = 0;
int state2 = 0;
int state3 = 0;
int currentState = 1;

int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;

void setup() {
  // set motor pin
  //pinMode(motorKiriA, OUTPUT);
  //pinMode(motorKananA, OUTPUT);
  //pinMode(motorKiriB, OUTPUT);
  //pinMode(motorKananB, OUTPUT);

  // for serial communication
  Serial.begin(9600);
  
}

void loop() {
  s1 = analogRead(sensor1);
  s2 = analogRead(sensor2);
  s3 = analogRead(sensor3);
  s4 = analogRead(sensor4);
  s5 = analogRead(sensor5);
  s6 = analogRead(sensor6);
  
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);

  int result = checkInput();
  updateState(result); 
  followLine(result);
  checkState();

  Serial.println("------ ");
 
  delay(1000);
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
    if(s6 < batas) {
      input += B000000;
    }
    else {
      input += B000001;
    }
    if(s5 < batas) {
      input += B000000;
    }
    else {
      input += B000010;
    }
    if(s4 < batas) {
      input += B000000;
    }
    else {
      input += B000100;
    }
    if(s3 < batas) {
      input += B000000;
    }
    else {
      input += B001000;
    }
    if(s2 < batas) {
      input += B000000;
    }
    else {
      input += B010000;
    }
    if(s1 < batas) {
      input += B000000;
    }
    else {
      input += B100000;
    }
    return input;
  }

void followLine(int input) {
    if(input == B110011 || input == B000000 || input == B100001 || input == B000001 || input == B100000 || input == B100011 || input == B1100001) {
      Serial.println("maju");
    }
    else if (input == B110111 || input == B101111 || input == B100111 || input == B001111) {
      Serial.println("belok kiri");
    }

    else if(input == B011111 || input == B001111 || input == B000111 || input == B000011) {
      Serial.println("belok kiri 90 derajat");
    }

    else if(input == B111011 || input ==  B111101 || input == B111001 || input == B111100) {
      Serial.println("belok kanan");
    }

    else if(input == B111110 || input == B111100 || input == B111000 || input == B110000) {
      Serial.println("belok kanan 90 derajat");
    }

    else if(input == B101101 || input == B001100) {
      Serial.prinltn("belok kiri");
    }
    else if(input == B111111) {
      if(previousState() != B111111) {
        state3 = previousState();
        Serial.println("Menjalani State Sebelumnya");
      }
      else {
        Serial.println("muter 180 derajat");  
      }
    }
  }

void checkState() {
    currentState++;
    if(currentState > 2) {
      currentState = 1;
    }
}

void updateState(int value) {
  if(currentState == 1) {
    state1 = value;
    }
  else {
    state2 = value;
    }
}

int previousState() {
  if(currentState == 1) {
    return state2;
    }
  else {
    return state1;
    }
}
