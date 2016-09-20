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
const int counter = 1;
int counterTemp = 0;

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
  // put your main code here, to run repeatedly:
  counterTemp = updateCounter(counterTemp);

}

int updateCounter(int previousCounter) {
    if(previousCounter < counter) {
      return ++previousCounter;
      }
     else {
      return 0;
      }
  }
  
