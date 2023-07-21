//adhishvairagade
/*
This Arduino code uses a Servo motor and an inductive sensor to detect the presence of metal. 
When metal is detected, the Servo motor moves to 45 degrees and remains in that position for 2 seconds. 
The inductive sensor is connected to digital pin 2, and the Servo motor is connected to digital pin 9. 
The initial Servo position is set to 90 degrees.
*/
#include <Servo.h>

const int inductiveSensorPin = 2;
const int servoPin = 9;
Servo myservo;

void setup() {
  pinMode(inductiveSensorPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(90);  // Move the servo to its initial position (90 degrees)
  Serial.begin(9600);
}

void loop() {
  int metalDetected = digitalRead(inductiveSensorPin);
  if (metalDetected == HIGH) {
    Serial.println("Metal detected!");
    moveServoToPosition(45);
    delay(2000);  // Adjust the delay time to control how long the servo stays at 45 degrees
  }
}

void moveServoToPosition(int angle) {
  myservo.write(angle);
}
