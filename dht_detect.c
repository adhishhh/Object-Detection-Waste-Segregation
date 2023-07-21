//adhishvairagade
/*
This Arduino code uses a DHT sensor to read humidity levels. 
When humidity falls below the set threshold, 
a servo motor moves to 45 degrees, 
and humidity readings are printed to the serial monitor.
*/
  #include <Servo.h>
  #include <DHT.h>
  
  const int dhtPin = 2;     // Pin connected to the DHT sensor
  const int servoPin = 9;
  Servo myservo;
  DHT dht(dhtPin, DHT22);   // Change to DHT11 if using DHT11 sensor
  int humidityThreshold = 50; // Adjust this threshold based on your requirement
  
  void setup() {
    pinMode(dhtPin, INPUT);
    myservo.attach(servoPin);
    myservo.write(90);  // Move the servo to its initial position (90 degrees)
    Serial.begin(9600);
    dht.begin();
  }
  
  void loop() {
    delay(2000);  // DHT sensors require a short delay before reading
    float humidity = dht.readHumidity();
    if (!isnan(humidity) && humidity < humidityThreshold) {
      Serial.print("Humidity is low: ");
      Serial.print(humidity);
      Serial.println("%");
      moveServoToPosition(45);
      delay(2000);  // Adjust the delay time to control how long the servo stays at 45 degrees
    }
  }
  
  void moveServoToPosition(int angle) {
    myservo.write(angle);
  }
