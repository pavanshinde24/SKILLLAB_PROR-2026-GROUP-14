#include "Sensors.h"
#include "Config.h"
#include <NewPing.h>
#include <Servo.h>

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo neckServo;
unsigned long lastSensorCheck = 0; 

void initSensors() {
  pinMode(LEFT_IR_PIN, INPUT);
  pinMode(RIGHT_IR_PIN, INPUT);
  neckServo.attach(SERVO_PIN);  
  neckServo.write(115); 
}

void updateSensors() {
  // Non-blocking sonar ping
  if (millis() - lastSensorCheck > 50) {
    int rawDistance = sonar.ping_cm();
    distanceAhead = (rawDistance == 0) ? 250 : rawDistance; 
    lastSensorCheck = millis();
  }
  
  // Read side IRs
  leftWallDetected = (digitalRead(LEFT_IR_PIN) == LOW);
  rightWallDetected = (digitalRead(RIGHT_IR_PIN) == LOW);
}

int lookRight() { 
  neckServo.write(50); 
  delay(500); 
  int dist = sonar.ping_cm(); 
  neckServo.write(115); 
  return (dist == 0) ? 250 : dist; 
}

int lookLeft() { 
  neckServo.write(170); 
  delay(500); 
  int dist = sonar.ping_cm(); 
  neckServo.write(115); 
  return (dist == 0) ? 250 : dist; 
}