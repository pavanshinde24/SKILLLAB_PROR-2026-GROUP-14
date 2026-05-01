# SKILL LAB PRATICAL HACKATHON

## Final Project README

# 1. Team Identity

## 1.1 Studio / Group Name

`Group-14`

## 1.2 Team Members

| Name                  | Primary Role                    | Secondary Role   | Strengths Brought to the Project |
| --------------        | ------------------------------- | --------------   | -------------------------------- |
| `Prasad Rane`         | `[Hardware / Coding / App ]`    | `[Integration]`  | `Main Lead and overall Handling `|
| `Yash Behere`         | `[Hardware Co-odinator]`        | `[Documentation]`| `Material Handling, Hardware`    |
| `Shaunak Chaudhari`   | `[Software]`                    | `[Testing]`      | `Software and testing`           |
| `Pavan Shinde`        | `[Github/Documentation]`        | `[Testing]`      | `Documentation and updates`      |

## 1.3 Project Title

`"S.A.V.E - Smart Anti-theft Vehicle Ecosystem"`

## 1.4 One-Line Pitch

`A tri-state secured IoT vehicle featuring remote React web dashboard control, local RFID access, and instant hardware-level crash prevention reflexes.`

## 1.5 Expanded Project Idea

`Nexus Robotics is an integrated IoT Ecosystem that bridges high-level web management with low-level hardware control to create a highly resilient "Smart Vehicle." The system features a dual-layer intelligence architecture:`

- `The "Brain" (Raspberry Pi): Runs a Flask server and React dashboard. It handles Wi-Fi commands, Emergency OTP unlocking, local RFID tag verification, and the capacitive touchanti-theft system.` 

- `The "Muscles & Reflexes" (Arduino Uno): Receives movement commands via USB serial. However, to prevent crashes from network latency, the Arduino relies on its  own "Reflexes"—an array of Ultrasonic and IR sensors that instantly kill power to the motors and auto-correct steering if a physical obstacle is detected, acting  entirely independent of the web server.`

# 2. Inspiration

## 2.1 References

| **Source Type** | **Title / Link** | **What Inspired You** |
| --- | --- | --- |
| `Concept` | `[ Modern Automotive Security Systems]` | `How modern cars use a mix of key fobs (RFID) and remote app unlocking (OTP/Web).` |
| `Concept` | `[ Industrial Robotics Safety]` |  `Hardware-level kill switches (Sensors -> Arduino) that bypass software lag to save hardware.` |

## 2.2 Original Twist 

`What makes your project original? Most hackathon RC cars are fully Raspberry Pi-controlled and tend to crash when the Wi-Fi lags. Our twist is the split   
 architecture. The Pi handles the heavy web UI and security authentication, while the Arduino acts as an independent reflex system. If the Pi tells the car to 
 drive forward, but the Arduino's sensors detect a wall, the Arduino overrides the Pi, stops the car, and ignores further drive commands until the path is clear.`
 
# 3. Project Intent

## 3.1 User Journey  
`The user approaches the locked rover. They can either tap their physical HW-147 RFID keychain on the car's scanner, or log into the React dashboard on their 
 phone and enter the 6-digit Emergency OTP. Upon verification, the dashboard flashes green ("UNLOCKED"). The user uses the on-screen joystick to drive the car. If 
 they accidentally drive the car straight at a wall, the front Ultrasonic sensor detects it. The Arduino instantly cuts motor power. If they drift too close to a 
 side wall, the side IR sensors trigger the Arduino to briefly counter-steer to avoid scraping. If an unauthorized person touches the locked car, the capacitive 
 touch sensor triggers an alarm, flashing the LED boards and sending a red alert to the web dashboard.`
                                                  |
# 4. Definition of Success

## 4.1 Definition of “Usable”
`The dashboard can successfully unlock the car via OTP, the Pi can read an RFID card via SPI,
 and the car can drive forward/backward via Serial commands without the Raspberry Pi losing
 power.`
 
## 4.2 Minimum Usable Version

`OTP Web Unlock -> USB Serial Command to Arduino -> Motors spin. The front ultrasonic sensor
 successfully stops the car if an object is placed in front of it.`
 
## 4.3 Stretch Features

- `Hardware-level side-collision avoidance using IR Sensors wired to the Arduino's analog pins.`
- `Capacitive touch-based anti-theft panic alarm wired directly to the Pi's GPIO.`
- `A "Parking Card" RFID feature that displays a contact screen on the web dashboard.`

# 5. System Overview

## 5.1 Project Type

- [x] `Electronics-based`

- [ ] `Mechanical`

- [x] `Sensor-based`

- [x] `App-connected`

- [x] `Motorized`

- [ ] `Sound-based`

- [ ] `Light-based`

- [x] `Screen/UI-based`

- [x] `Fabricated structure`

- [ ] `Game logic based`

- [ ] `Installation`

- [ ] `Other:`

## 5.2 High-Level System Description

- `INPUT 1 (Digital): React Dashboard sends OTP and drive commands over Wi-Fi to the Pi.`
- `INPUT 2 (Security): RFID HW-147 reads cards (SPI), and Touch sensor detects tampering (GPIO 17).`
- `PROCESSING 1 (Brain): Pi Flask server validates inputs, handles security, and sends Serial chars (U, F, B, L, R, S) via USB.`
- `PROCESSING 2 (Reflexes): Arduino reads USB commands AND local Collision Sensors (Ultrasonic/IR).`
- `OUTPUT 1 (Physical): Arduino drives L293D shield, Servo, and 4 BO Motors.`
- `OUTPUT 2 (Digital): Pi emits Socket.IO updates to update the React UI and flashes LED Arrow boards on alarm.`

## 5.3 Input / Output Map

| **System Part** | **Type** | **What It Does** |
| --- | --- | --- |
| `React Dashboard` | `Input/Output`| `Takes OTP/Drive inputs, displays Live Status/Telemetry.` |
| `HW-147 RFID Scanner` | `Input` | `Reads physical key fobs for local unlocking.` |
| `Capacitive Touch Sensor` | `Input` | `Detects unauthorized physical tampering.` |
| `Raspberry Pi (Flask)` | `Processing` | `Web server, Security validation, and Serial Master` |
| `Ultrasonic & IR Sensors` | `Input` | `Hardware-level collision detection for the front and sides.` |
| `Arduino Uno` | `Processing` | `Translates serial commands to motor movement and manages sensor reflexes.` |
| `L293D Motor Shield` | `Output` | `Physically drives the 4WD chassis. |

# 6. System Design, Sketches and Visual Planning 

## 6.1 Concept Architecture/sketch/schematic

 `graph TD`
 
     classDef ui fill:#1e40af,stroke:#60a5fa,stroke-width:2px,color:#fff;
 
     classDef pi fill:#b91c1c,stroke:#f87171,stroke-width:2px,color:#fff;
 
     classDef arduino fill:#0369a1,stroke:#38bdf8,stroke-width:2px,color:#fff;
 
     classDef sensor fill:#166534,stroke:#4ade80,stroke-width:2px,color:#fff;
 
     classDef motor fill:#b45309,stroke:#fbbf24,stroke-width:2px,color:#fff;
     
 
     Dash[ Web Dashboard]:::ui
 
     Pi[ Raspberry Pi]:::pi
 
     RFID[ HW-147 RFID]:::sensor
 
     Touch[ Touch Sensor]:::sensor
 
     Uno[ Arduino Uno]:::arduino
 
     Sensors[ Ultrasonic & IR Sensors]:::sensor
 
     Shield[ L293D Motor Shield]:::motor
 
     Motors[ 4x BO Motors & Servo]:::motor
 
     LEDs[ Alarm LEDs]:::ui
     
 
     Dash <-->|Wi-Fi: OTP & Commands| Pi
 
     RFID -->|SPI: 3.3V Logic| Pi
 
     Touch -->|GPIO 17| Pi
 
     Pi -->|GPIO 27| LEDs
 
     Pi <-->|USB: Serial Commands 'U', 'F'| Uno
 
     Sensors -->|Pins A0-A3| Uno
 
     Uno -->|PWM Signals| Shield
 
     Shield -->|11.1V Power| Motors

## 6.2 Labeled Build Sketch/architecture/flow diagram/algorithm

<img width="1280" height="814" alt="car2 img" src="https://github.com/user-attachments/assets/2527ea44-ed70-4a4c-96ec-826e19273f9f" />

## 6.3 Approximate Dimensions

| Dimension        | Value   |
| ---------------- | ------- |
| Length           | `16 cm` |
| Width            | `16 cm` |
| Height           | `8 cm`  |
| Estimated weight | `400 g` |

---

# 7. Electronics Planning

## 7.1 Electronics Used

| Component                 | Quantity | Purpose                               |
| ------------------------- | --------:| ------------------------------------- |
| `[Raspberry Pi]`                 | `1`      | `[ Main server, Wi-Fi, RFID handling, Alarm trigger]`                   |
| `[Arduino Uno]`    | `1`      | `[ Hardware controller and reflex logic]`                    |
| `[L293D Motor Shiel]`             | `1`      | `[ High-current driver for Motor]`                     |
| `[BO Motors]`        | `4`      | `[4WD Rotate wheels]`                       |
| `[SG90 Servo Motor]`   | `1`      | `[Sweeps the Ultrasonic sensor left/right]`                             |
| `[HW-147 RFID Modul]`             | `1`      | `[ Physical security access (Key & Parking Card)]`                 |
| `[Ultrasonic HC-SR04]` | `1`      | `[ Front collision detection]` |
| `[IR Sensors]`   | `2`      | `[ Left/Right side collision detection]`                             |
| `[Capacitive Touch Sensor]`             | `1`      | `[  Anti-theft tampering detection]`                 |
| `[Custom LED Boards]` | `2`      | `[  Visual alarm indicators]` |

## 7.2 Wiring Plan

- `The Brain (Raspberry Pi): * HW-147 RFID module connected to 3.3V native SPI pins (SDA/SS to GPIO 8, SCK to GPIO 11, MOSI to GPIO 10, MISO to GPIO 9).`
  
       - Touch sensor connected to GPIO 17.
       - Alarm LEDs connected to GPIO 27.
       - Pi connects to the Arduino via a standard USB A-to-B cable (/dev/ttyUSB0).
 
 - `The Muscle (Arduino Uno & Shield): * L293D Motor shield sits on top of the Arduino.`
   
       - 4 BO motors connect to M1, M2, M3, M4.
       - SG90 Servo connects to SER1 (Pin 10).
   
- `The Reflexes (Arduino Analog Pins): * Ultrasonic Trig -> A0, Echo -> A1.`
  
      - Left IR -> A2.
      - Right IR -> A3.

## 7.3 Circuit Diagram/architecture diagram

Insert a hand-drawn or software-made circuit diagram.

**Insert image below:**  
`[Upload image and link here]`
<img width="867" height="1156" alt="" src="" />


# 7.4. Power Plan

| Question         | Response                                                                                                                                          |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| Power source     | `Orange 11.1V 3S Li-Po for Motors + Separate 5V Power Bank for Pi`                                                                                                                           |
| Voltage required | `11.1V for Motors, 5V for Arduino/Pi, 3.3V for RFID.`                                                                  |
| Safety concerns  | `CRITICAL: Removed the PWR jumper next to the EXT_PWR block on the Motor Shield.This keeps the 11.1V battery completely isolated from the Arduino's logic power, preventing the Raspberry Pi's USB port from being overloaded or fried.` |

# 8. Software Planning/

## 8.1 Software Tools

| Tool / Platform                | Purpose                                        |
| ------------------------------ | ---------------------------------------------- |
| `[React & Tailwind CSS]`                | ` Build the interactive Web Dashboard UI.`                                |
| `[Python / Flask / SocketIO]`       | ` Host server on Pi, manage State, GPIO reads, and USB Serial.` |
| `[C++ / Arduino IDE]` | ` Motor control, sensor reading, reflex logic.`                      |

## 8.2 Software Logic/Algorithm

1. Startup: Pi boots, starts Flask server, and begins RFID/Touch background thread. Arduino boots, attaches sensors, and waits in a LOCKED state.

2. Input (Unlock): User enters OTP on React OR scans Master RFID tag. Pi sends U via USB.

3. Decision (Movement): User presses "Forward". Pi sends F. Arduino checks Ultrasonic ping_cm(). If path is clear, Arduino powers L293D.

4. Reflex Override: If car is moving and the Left IR detects a wall (reads LOW), the Arduino instantly veers right, completely bypassing the Pi to save time. If Ultrasonic detects a frontal wall under 30cm, motors halt instantly and evaluate left/right distances using the servo.

## 8.3 Code Flowchart

Insert a flowchart showing your code logic.

Suggested sequence:

- start,
- initialize,
- wait for input,
- read input,
- decision,
- trigger output,
- repeat or reset,
- error handling.

**Insert image below:**  
<img width="1600" height="1200" alt="image" src="" />
<img width="1600" height="1200" alt="image" src="" />




# 9. Bill of Materials

## 9.1 Full BOM

| Item                             | Quantity | In Kit? | Need to Buy? | Estimated Cost | Material / Spec               | Why This Choice?          |
| -------------------------------- | --------:| ------- | ------------ | --------------:| ----------------------------- | ------------------------- |
| `[RASPI]`                        | `1`      | `Yes`   | `No`         | `0`            | `38 Pin ESP32`                | `[To control components]` |
| `[Motor Driver]`                 | `[1]`    | `[Yes]` | `[No]`       | `0`            | `[LN296]`                     | `[To drive both motors]`  |
| `[DC Motors and wheel]`          | `[2]`    | `[No]`  | `[Yes]`      | `[150]`        | `[BO Motors and 6 cm wheels]` | `[high torque motors]`    |
| `[Buck Converter]`               | `[1]`    | `[No]`  | `[Yes]`      | `[75]`         |                               |                           |
| `[Li-ion batteries with holder]` | `[1]`    | `[No]`  | `[Yes]`      | `[200]`        |                               |                           |

## 9.2 Material Justification

Explain why you selected your main materials and components.

**Response:**  
`DC motors (BO motors) were chosen instead of servos or steppers because the system requires continuous rotation for movement rather than precise angular control (Previously, we were considering using steppers as we were planning on tracking movement on the ESP using its relative position from an origin, but since we're using a camera now, this is not required). A motor driver (L298N) was used to allow bidirectional control and speed variation using PWM.`


## 9.3 Items You chose

| Item                 | Why Needed               | Purchase Link | Latest Safe Date to Procure | Status       |
| -------------------- | ------------------------ | ------------- | --------------------------- | ------------ |
| `BO Motors + Wheels` | `Drive system for car`   | `robu.in`     | `15th April`                | `[Received]` |
| `Buck Converter`     | `Stable power for ESP32` | `local store` | `before testing`            | `[Received]` |
| `Li-ion Batteries`   | `Portable power`         | `local store` | `before testing`            | `Recieved`   |

## 9.4 Budget Summary

| Budget Item           | Estimated Cost              |
| --------------------- | ---------------------------:|
| Electronics           | `[400]`                     |
| Mechanical parts      | `[200]`                     |
| Fabrication materials | `[0 (Available on campus)]` |
| Purchased extras      | `[0]`                       |
| Contingency           | `[300]`                     |
| **Total**             | `[900]`                     |

## 9.5 Budget Reflection

If your cost is too high, what can be simplified, removed, substituted, or shared?

**Response:**  

---

# 10. Planning the Work

## 10.1 Team Working Agreement

Write how your team will work together.

Include:

- how tasks are divided,
- how decisions are made,
- how progress will be checked,
- what happens if a task is delayed,
- how documentation will be maintained.

**Response:**  


## 10.2 Task Breakdown

| Task ID | Task                    | Owner    | Estimated Hours | Deadline     | Dependency | Status |
| ------- | ----------------------- | -------- | ---------------:| ------------ | ---------- | ------ |
| T1      | `[Finalize concept]`    | `[Both]` | `2`             | `1st April`  | `None`     | `Done` |


## 10.3 Responsibility Split

| Area                 | Main Owner     | Support Owner |
| -------------------- | ----------     | ------------- |
| Concept              | `[Mrugendra]`  | `[Jyoti]`     |
| Electronics          | `[]`           | `[]`          |
| Coding               | `[]`           | `[]`          |
| Mechanical build     | `[]`           | `[]`          |
| Testing              | `[]`           | `[]`          |
| Documentation        | `[]`           | `[]`          |

---

# 11 hour Milestones

## 11.1 8-hour Plan(tentetively you may set)

### Bi Hour 1 — Plan and De-risk

Expected outcomes:

- [x] Idea finalized
- [x] Core interaction decided
- [x] Sketches made
- [x] BOM completed
- [x] Purchase needs identified
- [ ] Key uncertainty identified
- [x] Basic feasibility tested

### Bi Hour 2 — Build Subsystems

Expected outcomes:

- [x] Electronics tests completed
- [ ] CAD / structure planning completed
- [ ] App UI started if needed
- [x] Mechanical concept tested
- [x] Main subsystems partially working

### Bi Hour 3 — Integrate

Expected outcomes:

- [x] Physical body built
- [x] Electronics integrated
- [x] Code connected to hardware
- [ ] App connected if required
- [x] First playable version exists

### Bi Hour 4 — Refine and Finish

Expected outcomes:

- [x] Technical bugs reduced
- [x] Playtesting completed
- [x] Improvements made
- [x] Documentation completed
- [x] Final build ready

## 12.2  Update Log

| Days   | Planned Goal   | What Actually Happened | What Changed   | Next Steps     |
| ------ | -------------- | ---------------------- | -------------- | -------------- |
| Day 1 | `[Write here]` | `[Write here]`         | `[Write here]` | `[Write here]` |
| Day 2 | `[Write here]` | `[Write here]`         | `[Write here]` | `[Write here]` |
| Day 3 | `[Write here]` | `[Write here]`         | `[Write here]` | `[Write here]` |
| Day 4 | `[Write here]` | `[Write here]`         | `[Write here]` | `[Write here]` |

---

# 13. Risks and Unknowns

## 13.1 Risk Register

| Risk                                                            | Type         | Likelihood | Impact   | Mitigation Plan                                                                       | Owner                |
| --------------------------------------------------------------- | ------------ | ---------- | -------- | ------------------------------------------------------------------------------------- | -------------------- |
| WiFi connection between laptop and ESP32 becomes unstable       | `Technical`  | `Medium`   | `High`   | Keep ESP32 close, ensure stable power supply, reduce network load, add fail-safe stop | `[Gopal]`           |


## 13.2 Biggest Unknown Right Now

What is the single biggest uncertainty in your project at this stage?

**Response:**  


---

# 14. Testing 

## 14.1 Technical Testing Plan

| What Needs Testing     | How You Will Test It                                                                 | Success Condition                                                                                    |
| ---------------------- | ------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------- |
| `[Wifi connection]`    | `[Check if motor spins via app button]`                                              | `[Both motors accurately respond to wifi signals]`                                                   |
                       |
## 14.2 Testing and Debugging Log

| Date          | Problem Found                         | Type         | What You Tried                                | Result               | Next Action                                    |
| ------------- | ------------------------------------- | ------------ | --------------------------------------------- | -------------------- | ---------------------------------------------- |
| `18th April`  | `Car not balancing properly`          | `Mechanical` | `Add low-friction caster support to one side` | `Worked`             | `improve caster structure`                     |


## 14.3 Playtesting Notes

| Tester      | What They Did                        | What Confused Them                    | What They Enjoyed                         | What You Will Change                          |
| ----------- | ------------------------------------ | ------------------------------------- | ----------------------------------------- | --------------------------------------------- |
| `Gopal` | `Tried navigating through obstacles` | `Some obstacles ewren't clear enough` | `Liked projection + real car interaction` | `Add a slight red highlight around obstacles` |


---

# 15. Build Documentation

## 15.1 Fabrication Process(if any)

Describe how the project was physically made.

Include:

- cutting,
- 3D printing,
- assembly,
- fastening,
- wiring,
- finishing,
- revisions.

**Response:**  
`The fabrication process involved designing, manufacturing, assembling, and refining both the physical structure and electronic integration of the system.`

`Design (CAD Modeling):
The initial model was created using CAD software, where components were designed based on the actual dimensions of the electronic parts. This ensured accurate fitting and minimized errors during assembly.
Cutting (Laser Cutting):
The designed parts were fabricated using laser cutting techniques. Sheets were cut precisely according to the CAD model to create the structural base and mounts for components.`

`Components were fixed using adhesives and mechanical supports. Certain parts were intentionally kept modular (not permanently fixed) to allow easy replacement and modification of electronics.
Surface Finishing:
Some parts were sanded to smooth rough edges after cutting. Sawdust mixed with adhesive was used to fill gaps and uneven edges, improving structural finish. The final structure was then painted for better aesthetics and durability.`

`Environment Setup (Dark Room Fabrication):
To enhance projection visibility, a controlled dark environment was created using Z-boards, paper sheets, and bedsheets. This minimized external light interference and improved projection clarity.
Revisions and Iterations:
Multiple adjustments were made throughout the process, including refining alignment, improving structural stability, repositioning components, and optimizing the interaction between the physical car and projected environment.`

## 16 Build Photos

Add photos throughout the project.

Suggested images:

- early sketch,
- prototype,
- electronics testing,
- mechanism test,
- app screenshot,
- final build.
- <img width="960" height="1280" alt="WhatsApp Image 2026-04-24 at 9 46 02 AM (1)" src="https://github.com/user-attachments/assets/74baa570-5770-483e-be6d-d2f03386e37c" />





# 17. Final Outcome

## 17.1 Final Description

Describe the final version of your project.

**Response:**  


## 17.2 What Works Well



## 17.3 What Still Needs Improvement


## 17.4 What Changed From the Original Plan

How did the project change from the initial idea?

**Response:**  


---

# 18. Reflection

## 18.1 Team Reflection

What did your team do well?  
What slowed you down?  
How well did you manage time, tasks, and responsibilities?

**Response:**  


## 18.2 Technical Reflection

What did you learn about:

- electronics,
- coding,
- mechanisms,
- fabrication,
- integration?

**Response:**  


## 18.3 Design Reflection

What did you learn about:

- designing ,
- delight,
- clarity,
- physical interaction,
- understanding,
- iteration?

**Response:**  


## 18.4 If You Had One More hour

What would you improve next?

**Response:**  

` `

---

# 19. Final Submission Checklist

Before submission, confirm that:

- [x] Team details are complete
- [x] Project description is complete
- [x] Inspiration sources are included
- [x] Sketches are added
- [x] BOM is complete
- [x] Purchase list is complete
- [x] Budget summary is complete
- [x] Mechanical planning is documented if applicable
- [ ] App planning is documented if applicable
- [x] Code flowchart is added
- [x] Task breakdown is complete
- [x] Weekly logs are updated
- [x] Risk register is complete
- [x] Testing log is updated
- [x] Playtesting notes are included
- [x] Build photos are included
- [x] Final reflection is written
<img width="1131" height="1600" alt="image" src="" />

---


---


