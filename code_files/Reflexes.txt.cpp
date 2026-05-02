#include "Reflexes.h"
#include "Config.h"
#include "Motors.h"
#include "Sensors.h"
#include "Comms.h"

void runAutopilotReflexes() {
  if (distanceAhead <= DANGER_ZONE) {
    Serial.println("ALERT:OBSTACLE_FRONT");
    stopCar(); delay(100);
    driveBackward(); delay(300);
    stopCar(); delay(200);
    
    int spaceOnRight = lookRight();
    int spaceOnLeft = lookLeft();

    if (spaceOnRight >= spaceOnLeft) {
      turnRight(); delay(500); 
    } else {
      turnLeft(); delay(500);
    }
    stopCar();
  } 
  else if (leftWallDetected) { turnRight(); delay(150); } 
  else if (rightWallDetected) { turnLeft(); delay(150); } 
  else { driveForward(); }
}

void runManualSafetyReflexes() {
  if (currentDriveCommand == 'F') {
    if (distanceAhead <= (DANGER_ZONE - 5)) {
      stopCar();
      currentDriveCommand = 'S'; 
      Serial.println("ALERT:OBSTACLE_FRONT"); 
    } 
    else if (leftWallDetected) { turnRight(); delay(100); executeDriveCommand(); } 
    else if (rightWallDetected) { turnLeft(); delay(100); executeDriveCommand(); }
  }
}