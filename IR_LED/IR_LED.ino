// IR sensor
const int sensorKiri = 1;
const int sensorKanan = 2;

// LED
const int ledKiri = 12;
const int ledKanan = 13;


void setup() {
   // set IR sensor pin
  pinMode(sensorKiri, INPUT);
  pinMode(sensorKanan, INPUT);

  //set LED sensor pin
  pinMode(ledKiri, OUTPUT);
  pinMode(ledKanan, OUTPUT);

   // for serial communication
  Serial.begin(9600);

  // set LED to default
  digitalWrite(ledKiri, LOW);
  digitalWrite(ledKanan, LOW);
  
}

void loop() {
  float s1 = digitalRead(sensorKiri);
  float s2 = digitalRead(sensorKanan);

  // print ke serial monitor
  Serial.println(s1);
  Serial.println(s2);

  if(s2 == HIGH && s1 == LOW) {
    digitalWrite(ledKanan, HIGH);
    digitalWrite(ledKiri, LOW);
    
    Serial.println("Belok kanan");
   }
   else if (s1 == HIGH && s2 == LOW) {
    digitalWrite(ledKiri, HIGH);
    digitalWrite(ledKanan, LOW);

    Serial.println("Belok kiri");
   }
   else if (s1 == LOW && s2 == LOW) {
    digitalWrite(ledKiri, LOW);
    digitalWrite(ledKanan, LOW);

    Serial.println("Berhenti");
   }
   else if(s1 == HIGH && s2 == HIGH) {
    digitalWrite(ledKiri, HIGH);
    digitalWrite(ledKanan, HIGH);

    Serial.println("Maju");
    }

   Serial.println("------");
}
