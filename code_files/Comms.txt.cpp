#include "Comms.h"
#include "Config.h"
#include "Motors.h"

void initComms() {
  Serial.begin(9600); 
  Serial.println("SYS:READY"); 
}

void checkComms() {
  if (Serial.available() > 0) {
    char incomingCommand = Serial.read();
    processRemoteCommand(incomingCommand);
  }
}

void processRemoteCommand(char cmd) {
  switch(cmd) {
    case 'U': 
      isCarLocked = false; 
      Serial.println("STATE:UNLOCKED"); break;
    case 'L': 
      isCarLocked = true; isAutopilotEnabled = false; 
      stopCar(); Serial.println("STATE:LOCKED"); break;
    case 'A': 
      if(!isCarLocked) { isAutopilotEnabled = true; currentDriveCommand = 'S'; } break;
    case 'M': 
      isAutopilotEnabled = false; stopCar(); break;
    case 'F': 
    case 'B': 
    case 'R': 
    case 'E': 
    case 'S': 
      if (!isCarLocked && !isAutopilotEnabled) {
        currentDriveCommand = cmd;
        executeDriveCommand();
      }
      break;
  }
}

void executeDriveCommand() {
  switch(currentDriveCommand) {
    case 'F': driveForward(); break;
    case 'B': driveBackward(); break;
    case 'R': turnRight(); break;
    case 'E': turnLeft(); break;
    case 'S': stopCar(); break;
  }
}