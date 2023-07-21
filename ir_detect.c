//adhishvairagade
/*
This code is an Arduino sketch that controls a servo motor based on input from an infrared (IR) motion sensor. 
The purpose of the code is to move the servo motor to a 90-degree angle whenever motion is detected by the IR sensor.
*/
#include <Servo.h>

const int irSensorPin = 2;
const int servoPin = 9;
Servo myservo;

void setup() {
  pinMode(irSensorPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(90);  // Move the servo to its initial position (90 degrees)
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(irSensorPin);
  if (motionDetected == HIGH) {
    Serial.println("Motion detected!");
    moveServoToPosition(90);
    delay(2000);  // Adjust the delay time to control how long the servo stays at 90 degrees
  }
}

void moveServoToPosition(int angle) {
  myservo.write(angle);
}
