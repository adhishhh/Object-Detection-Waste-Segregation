//adhishvairagade
/*
This Arduino code uses a Servo motor and a soil moisture sensor to monitor soil moisture levels. 
When moisture is below the threshold (500), it moves the Servo to 45 degrees for 2 seconds. 
The sensor is connected to A0, and the Servo is connected to pin 9 with an initial position of 90 degrees.
*/
/*
install the DHT sensor library. 
Go to Sketch -> Include Library -> Manage Libraries, 
search for "DHT" and install the appropriate library (DHT Sensor Library by Adafruit).
In our case add library from the github.
*/
#include <Servo.h>

const int soilMoistureSensorPin = A0;
const int servoPin = 9;
Servo myservo;
int moistureThreshold = 500; // Adjust this threshold based on your sensor readings

void setup() {
  pinMode(soilMoistureSensorPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(90);  // Move the servo to its initial position (90 degrees)
  Serial.begin(9600);
}

void loop() {
  int moistureLevel = analogRead(soilMoistureSensorPin);
  if (moistureLevel < moistureThreshold) {
    Serial.println("Soil moisture is low!");
    moveServoToPosition(45);
    delay(2000);  // Adjust the delay time to control how long the servo stays at 45 degrees
  }
}

void moveServoToPosition(int angle) {
  myservo.write(angle);
}
