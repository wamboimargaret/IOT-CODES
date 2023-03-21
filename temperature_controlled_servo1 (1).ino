#include <Servo.h>

#define temperature A0
#define ledIndicator 2

Servo mainServo;
int position = 0;
int previousPosition;

void setup() {
  
  pinMode(temperature, INPUT);
  pinMode(ledIndicator, OUTPUT);
  mainServo.attach(3);
  
  Serial.begin(9600);

}

void loop() {
  
  // Temperature analysis
  int tempReading = analogRead(temperature);
  // If using 5v input
  float voltage = tempReading * 5.0; 
  
  // Divided by 1024
  voltage /= 1024.0;
  //Converting from 10mv per degree
  float tempC = (voltage - 0.5) * 100;
  
  // This maps temperature to degreeS
  int position = map(tempC, 31, 125, 90, 180);
  Serial.println(position);
  if(previousPosition != position){
     mainServo.write(position);
  	 digitalWrite(ledIndicator, HIGH);
     delay(1000);
  }
     
  digitalWrite(ledIndicator, LOW);
  previousPosition = position;
}


