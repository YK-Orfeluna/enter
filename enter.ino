int flag = 0;
int sum = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  sum += sensorValue;
  flag ++;

  if(flag == 50){
    float distance = sum / 50;
    if (distance > 150){
      digitalWrite(7, HIGH);
    }
    else{
      digitalWrite(7, LOW);
    }
    flag = 0;
    sum = 0;
  }
  delay(1);        // delay in between reads for stability
}
