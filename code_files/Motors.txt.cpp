#include "Motors.h"
#include "Config.h"
#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

unsigned long lastBeepTime = 0;
bool beepState = false;

void initMotors() {
  stopCar();
}

void stopCar() { 
  motor1.run(RELEASE); motor2.run(RELEASE); 
  motor3.run(RELEASE); motor4.run(RELEASE); 
} 

void driveForward() { 
  motor1.run(FORWARD); motor2.run(FORWARD); 
  motor3.run(FORWARD); motor4.run(FORWARD); 
  setMotorSpeed(MAX_SPEED); 
}

void driveBackward() { 
  motor1.run(BACKWARD); motor2.run(BACKWARD); 
  motor3.run(BACKWARD); motor4.run(BACKWARD); 
  setMotorSpeed(MAX_SPEED); 
}  

void turnRight() { 
  motor1.run(BACKWARD); motor2.run(FORWARD); 
  motor3.run(FORWARD); motor4.run(BACKWARD); 
  setMotorSpeed(MAX_SPEED); 
} 

void turnLeft() { 
  motor1.run(FORWARD); motor2.run(BACKWARD); 
  motor3.run(BACKWARD); motor4.run(FORWARD); 
  setMotorSpeed(MAX_SPEED); 
}

void setMotorSpeed(int speed) { 
  motor1.setSpeed(speed); motor2.setSpeed(speed); 
  motor3.setSpeed(speed); motor4.setSpeed(speed); 
}

// ==========================================
// BUZZER LOGIC (Timer-Collision Free!)
// ==========================================

void playBootSound() {
  #if USE_BUZZER
    pinMode(BUZZER_PIN, OUTPUT);
    
    // We use analogWrite(128) to generate a hardware tone without using the Tone library!
    analogWrite(BUZZER_PIN, 128); delay(150);
    digitalWrite(BUZZER_PIN, LOW); delay(100);
    
    analogWrite(BUZZER_PIN, 128); delay(150);
    digitalWrite(BUZZER_PIN, LOW); delay(100);
    
    analogWrite(BUZZER_PIN, 128); delay(400);
    digitalWrite(BUZZER_PIN, LOW);
  #endif
}

void handleReverseBeeper(bool isReversing) {
  #if USE_BUZZER
    if (isReversing) {
      if (millis() - lastBeepTime > 400) { 
        beepState = !beepState;
        if (beepState) {
          analogWrite(BUZZER_PIN, 128); // BEEP ON
        } else {
          digitalWrite(BUZZER_PIN, LOW); // BEEP OFF
        }
        lastBeepTime = millis();
      }
    } else {
      digitalWrite(BUZZER_PIN, LOW);
      beepState = false;
    }
  #endif
}