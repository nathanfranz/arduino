#include <Servo.h>  // servo library

const int sensorPin = 0;
const int ledPin = 13;

Servo servo1;

int count = 0;

// We'll also set up some global variables for the light level:
int lightLevel, high = 0, low = 1023;


void setup() {
  pinMode(ledPin, OUTPUT);
  servo1.attach(9);
  servo1.write(90);

  Serial.begin(9600);
}

void loop() {
  lightLevel = analogRead(sensorPin);
  manualTune();

  if(lightLevel < 150)
  {
    count++;
    Serial.print(count);
    Serial.print(" : ");
    Serial.print(lightLevel);
    Serial.print(" ");
    pressPS4Button();
    delay(1000);
  }
}

void saveShit() 
{
  lightLevel = analogRead(sensorPin);

  servo1.write(90);    // Tell servo to go to 90 degrees

  delay(1000);         // Pause to get it time to move

  analogWrite(ledPin, lightLevel);
}

void manualTune()
{
  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}

void pressPS4Button() {
  servo1.write(45);
  delay(500);
  servo1.write(90);
}

