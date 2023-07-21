//adhishvairagade
/*
This Arduino code uses a Servo motor and capacitive sensor to detect metal. 
When metal is detected, the Servo moves to 45 degrees and stays for 2 seconds.
*/
#include <Servo.h>

const int capacitiveSensorPin = 2;
const int servoPin = 9;
Servo myservo;

void setup() {
  pinMode(capacitiveSensorPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(90);  // Move the servo to its initial position (90 degrees)
  Serial.begin(9600);
}

void loop() {
  int metalDetected = digitalRead(capacitiveSensorPin);
  if (metalDetected == HIGH) {
    Serial.println("Metal detected!");
    moveServoToPosition(45);
    delay(2000);  // Adjust the delay time to control how long the servo stays at 45 degrees
  }
}

void moveServoToPosition(int angle) {
  myservo.write(angle);
}
