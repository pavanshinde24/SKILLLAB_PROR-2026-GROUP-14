#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ==========================================
// MASTER SWITCHES
// ==========================================
#define USE_OLED false   // Set to true ONLY when screen is plugged in!
#define DEBUG_MODE true  // Prints live sensor data to the Serial Monitor
#define USE_BUZZER true  // Turns the reversing beeper on/off

// ==========================================
// HARDWARE PINS
// ==========================================
#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define LEFT_IR_PIN A2   
#define RIGHT_IR_PIN A3  
#define SERVO_PIN 10     
#define BUZZER_PIN 9     // Reversing beeper on SER2

// ==========================================
// CAR SETTINGS (These were missing!)
// ==========================================
#define MAX_DISTANCE 200 // Max sonar range in cm
#define MAX_SPEED 190    // Safe speed for motors
#define DANGER_ZONE 30   // Distance in cm to trigger instant brakes

// ==========================================
// GLOBAL MEMORY
// ==========================================
extern bool isCarLocked;
extern bool isAutopilotEnabled;
extern char currentDriveCommand;

extern int distanceAhead;
extern bool leftWallDetected;
extern bool rightWallDetected;

#endif