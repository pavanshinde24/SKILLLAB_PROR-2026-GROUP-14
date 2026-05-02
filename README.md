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

<img width="1698" height="926" alt="car3 img" src="https://github.com/user-attachments/assets/e6eaf82e-5635-4765-bf24-73d3353b3227" />

# 7.4. Power Plan

| Question         | Response                                                                                                                                          |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| `Power source`     | `Orange 11.1V 3S Li-Po for Motors + Separate 5V Power Bank for Pi`                                                                                                                           |
| `Voltage required` | `11.1V for Motors, 5V for Arduino/Pi, 3.3V for RFID.`                                                                  |
| `Safety concerns`  | `CRITICAL: Removed the PWR jumper next to the EXT_PWR block on the Motor Shield.This keeps the 11.1V battery completely isolated from the Arduino's logic power, preventing the Raspberry Pi's USB port from being overloaded or fried.` |

# 8. Software Planning/

## 8.1 Software Tools

| Tool / Platform                | Purpose                                        |
| ------------------------------ | ---------------------------------------------- |
| `[React & Tailwind CSS]`                | ` Build the interactive Web Dashboard UI.`                                |
| `[Python / Flask / SocketIO]`       | ` Host server on Pi, manage State, GPIO reads, and USB Serial.` |
| `[C++ / Arduino IDE]` | ` Motor control, sensor reading, reflex logic.`                      |

## 8.2 Software Logic/Algorithm

1. `Startup: Pi boots, starts Flask server, and begins RFID/Touch background thread. Arduino boots, attaches sensors, and waits in a LOCKED state.`

2. `Input (Unlock): User enters OTP on React OR scans Master RFID tag. Pi sends U via USB.`

3. `Decision (Movement): User presses "Forward". Pi sends F. Arduino checks Ultrasonic ping_cm(). If path is clear, Arduino powers L293D.`

4. `Reflex Override: If car is moving and the Left IR detects a wall (reads LOW), the Arduino instantly veers right, completely bypassing the Pi to save time. If Ultrasonic detects a frontal wall under 30cm, motors halt instantly and evaluate left/right distances using the servo.`

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
| `[Raspberry Pi 4]`                        | `[1]`      | `[Y]`  | `[N]`        | `[5000]`            | `[Web server brain]`                | `[To control components]` |
| `[Arduino Uno]`                 | `[1]`    | `[Y]` | `[N]`       | `[200]`            | `[ ATmega328P]`                     | `[To drive both motors]`  |
| `[L293D Motor Shield]`          | `[1]`    | `[Y]`  | `[N]`      | `[150]`        | `[ V1 Adafruit clone]` | `[high torque motors]`    |
| `[DC BO Motors]`               | `[4]`    | `[Y]`  | `[N]`      | `[200]`         |       `[Yellow plastic gear]`        |`[Standard robotics base]`       |
| `[HW-147 RFID]` | `[1]`    | `[Y]`  | `[N]`      | `[200]`        |             `[ 13.56MHz]`                      | `[Hardware Security]`      |
| `[HC-SR04]`                 | `[1]`    | `[Y]` | `[N]`       | `[100]`            | `[ Ultrasonic]`                     | `[ Front collision prevention]`  |
| `[IR Sensors]`          | `[2]`    | `[Y]`  | `[N]`      | `[150]`        | `[ Infrared]` | `[Side collision prevention]`    |
| `[Capacitive Touch]`               | `[1]`    | `[Y]`  | `[N]`      | `[100]`         |  `[ Digital output]`    |  `[Anti-theft detection]`                 |
| `[11.1V Li-Po Battery]` | `[1]`    | `[Y]`  | `[N]`      | `[1000]`        |  `[4500mAh 3S ]`     | `[ High discharge rate for 4 motors]`  |


## 9.2 Material Justification

`The selected materials are chosen to balance performance, cost, and ease of integration for the S.A.V.E. IoT vehicle system. The Raspberry Pi 4 acts as the central processing unit, enabling advanced tasks like web control and security handling, while the Arduino Uno efficiently manages real-time motor control using the L293D Motor Shield. The DC BO motors provide a reliable and low-cost mobility solution suitable for small robotic platforms. For sensing and safety, the HC-SR04 ultrasonic sensor and IR sensors ensure effective obstacle detection from multiple directions, while the capacitive touch sensor enhances security through anti-theft interaction. The HW-147 RFID module adds an additional layer of hardware-based authentication. Finally, the 11.1V Li-Po battery is selected for its high discharge capability, ensuring stable and sufficient power delivery to all four motors, making the system robust and efficient for continuous operation.`

## 9.3 Items You chose

| Item                 | Why Needed               | Purchase Link | Latest Safe Date to Procure | Status       |
| -------------------- | ------------------------ | ------------- | --------------------------- | ------------ |
| `Raspberry Pi 4` | `Main controller & web server`   | `Available (Campus)`     | `N/A`                | `[Received]` |
| `Arduino Uno`     | `Motor & sensor control` | `Available (Campus)` | `N/A`            | `[Received]` |
| `L293D Motor Shield`   | `Motor driving interface`         | `Available (Campus)` | `N/A`            | `Recieved`   |
| `DC BO Motors` | `Robot movement`   | `Available (Campus)`     | `N/A`                | `[Received]` |
| `HW-147 RFID`     | `Security authentication` | `Available (Campus)` | `N/A`            | `[Received]` |
| `HC-SR04`   | `Front obstacle detection`         | `Available (Campus)` | `N/A`            | `Recieved`   |
| `IR Sensors`     | `Side obstacle detection` | `Available (Campus)` | `N/A`            | `[Received]` |
| `Capacitive Touch`   | `Anti-theft interaction`         | `Available (Campus)` | `N/A`            | `[Recieved]`   |
| `11.1V Li-Po Battery`   | `Power supply for motors`         | `Available (Campus)` | `N/A`            | `[Recieved]`   |


## 9.4 Budget Summary

| Budget Item           | Estimated Cost              |
| --------------------- | ---------------------------:|
| Electronics           | `[0  (Available on campus)]`                     |
| Mechanical parts      | `[0  (Available on campus)]`                     |
| Fabrication materials | `[0 (Available on campus)]` |
| Purchased extras      | `[0  (Available on campus)]`                       |
| Contingency           | `[0  (Available on campus)]`                     |
| **Total**             | `[0]`                     |

## 9.5 Budget Reflection

Since all required components were provided by the campus, the project incurred no direct financial cost, making it highly budget-efficient. This allowed full focus on design, integration, and performance without procurement constraints. Even though the components (like Raspberry Pi, Arduino, sensors, and motors) have significant market value, utilizing institutional resources demonstrates cost optimization and effective resource management, which is ideal for academic prototyping and development.

# 10. Planning the Work

## 10.1 Team Working Agreement

`Tasks are divided by system layers: React UI, Pi/Python bridge, Arduino/C++ code, and physical
assembly/wiring. Decisions are made collaboratively. If Wi-Fi fails, we rely on RFID as a backup.
Documentation is maintained live in this GitHub repo.` 

## 10.2 Task Breakdown

| Task ID | Task                    | Owner    | Estimated Hours | Deadline     | Dependency | Status |
| ------- | ----------------------- | -------- | ---------------:| ------------ | ---------- | ------ |
| T1      | `[Hardware]`    | `[Prasad]` | `36`             | `1st May`  | `None`     | `Done` |
| T2     | `[Software]`    | `[Shaunak]` | `36`             | `1st May`  | `None`     | `Done` |
| T3      | `[Github]`    | `[Pavan]` | `36`             | `1st May`  | `None`     | `Done` |
| T4      | `[Documentation]`    | `[Yash]` | `36`             | `1st May`  | `None`     | `Done` |


## 10.3 Responsibility Split

| Area                 | Main Owner     | Support Owner |
| -------------------- | ----------     | ------------- |
| Concept              | `[Pavan]`  | `[Yash]`     |
| Electronics          | `[Prasad]`           | `[Yash]`          |
| Coding               | `[Shaunak]`           | `[Prasad]`          |
| Mechanical build     | `[Prasad]`           | `[Shaunak]`          |
| Testing              | `[Shaunak]`           | `[Pavan]`          |
| Documentation        | `[Yash]`           | `[Pavan]`          |

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
| Day 1 | `[Harware and Software Implementation]` | `[All Implemented]`         | `[All Worked]` | `[Updates]` |
| Day 2 | `[Updates]` | `[Updated]`         | `[All Worked]` | `[Final Submission]` |
| Day 3 | `[Final Submission]` | `[Pending]`         | `[Working]` | `[Improve the Project ]` |


---

# 13. Risks and Unknowns

## 13.1 Risk Register

| Risk                                                            | Type         | Likelihood | Impact   | Mitigation Plan                                                                       | Owner                |
| --------------------------------------------------------------- | ------------ | ---------- | -------- | ------------------------------------------------------------------------------------- | -------------------- |
|  `Power loop frying boards`        | `Hardware`  | ` Fatal`   | `High`   | `Removed the PWR jumper on the L293D shield to isolate the 11.1V battery from the Pi/Arduino 5V logic.`  | `[Prasad]`           |
|  `5V Logic mismatch with RFID`        | `Hardware`  | ` Fatal`   | `High`   | `The HW-147 is 3.3V. We moved it off the 5V Arduino and connected it to the Raspberry Pi's native 3.3V SPI pins`  | `[Yash]`           |
|  `SPI Pin conflicts`        | `Technical`  | `High`   | `High`   | `The Motor shield internally uses SPI pins. By moving the RFID to the Raspberry Pi, we completely bypassed this conflict.`  | `[Shaunak]`           |
|  `Code locking up`        | `Technical`  | `High`   | `High`   | ` Used a non-blocking timeout on the Ultrasonic ping functions to ensure the Arduino loop never hangs.`  | `[Pavan]`           |

## 13.2 Biggest Unknown Right Now

`The biggest uncertainty at this stage is the seamless integration and communication between the Raspberry Pi and Arduino, especially in handling real-time data exchange and synchronization. While individual components and modules function correctly in isolation, ensuring reliable coordination between high-level processing (Pi) and low-level control (Arduino) without latency or data loss remains a key challenge that could impact overall system performance.`

# 14. Testing 

## 14.1 Technical Testing Plan

| What Needs Testing     | How You Will Test It                                                                 | Success Condition                                                                                    |
| ---------------------- | ------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------- |
| `[OTP Auth]`    | `[Enter 123456 on React Web App]`                                              | `[Pi prints 'Unlocked', sends 'U' over Serial, Dashboard turns green.]`|
| `[Anti-Thef]`    | `[Touch the capacitive sensor]`                                              | `[Pi GPIO triggers LEDs to flash, UI shows red
"TAMPERING" alert.]`| 
| `[Drive Logic]`    | `[Press Forward on Dashboard]`                                              | `[All 4 BO Motors spin forward in unison.]`| 
| `[Crash Reflex]`    | `[Put hand in front of Ultrasonic]`                                              | `[Arduino cuts motor power instantly regardless of Pi
commands.]`| 
                       
## 14.2 Testing and Debugging Log

| Date          | Problem Found                         | Type         | What You Tried                                | Result               | Next Action                                    |
| ------------- | ------------------------------------- | ------------ | --------------------------------------------- | -------------------- | ---------------------------------------------- |
| `18th April`  | `Car not balancing properly`          | `Mechanical` | `Add low-friction caster support to one side` | `Worked`             | `improve caster structure`                     |


## 14.3 Playtesting Notes

| Tester      | What They Did                        | What Confused Them                    | What They Enjoyed                         | What You Will Change                          |
| ----------- | ------------------------------------ | ------------------------------------- | ----------------------------------------- | --------------------------------------------- |
| `Prasad` | `Tested RFID access and vehicle start` | `Delay in authentication response` | `Liked security feature with real-time control` | `Optimize RFID response time and feedback signal` |
| `Shaunak` | `Tested obstacle detection sensors` | `IR sensor detection range inconsistency` | `Liked automatic collision avoidance` | `Calibrate sensors for better accuracy` |
| `Pavan` | `Checked anti-theft touch functionality` | `UI buttons were not very intuitive` | `Enjoyed remote control feature` | `Improve UI design and add clearer labels` |
| `Yash` | `Controlled vehicle via web interface` | `Some obstacles ewren't clear enough` | `Liked projection + real car interaction` | `Add a slight red highlight around obstacles` |

# 15. Build Documentation

## 15.1 Fabrication Process(if any)

`None.`

## 16 Build Photos

<img width="738" height="1600" alt="car img" src="https://github.com/user-attachments/assets/56cfbe16-780e-4365-9c56-09c8399b82f3" />

<img width="738" height="1600" alt="car1 img" src="https://github.com/user-attachments/assets/9ba62fd6-3d27-4700-8ff1-c82803a8adb8" />

# 17. Final Outcome

## 17.1 Final Description

`The final version of the S.A.V.E. (Smart Autonomous Vehicle Environment) system is an IoT-based smart vehicle platform that integrates a Raspberry Pi for high-level processing and web control with an Arduino for real-time motor and sensor operations. It features RFID-based secure access, ultrasonic and IR sensors for multi-directional obstacle detection, and a capacitive touch sensor for anti-theft protection. The system allows remote monitoring and control through a web interface, while ensuring safe navigation and reliable performance through efficient hardware-software integration, making it a compact and intelligent prototype for smart vehicle applications.`

## 17.2 What Works Well

- `The Serial USB bridge between the Pi and Arduino.`
- `Hardware isolation (Pi handles 3.3V sensors, Arduino handles 5V/11V motors).`
- `Clean wiring using the A2 and A3 analog pins as digital inputs for the IR sensors.`

## 17.3 What Still Needs Improvement

`While the system is functional, it still needs improvements in response time, sensor accuracy, and overall system optimization. Communication between the Raspberry Pi and Arduino can be further refined to reduce latency. The obstacle detection system may require better calibration for consistent performance in different environments, and the web interface can be enhanced for a more user-friendly experience. Additionally, improving power efficiency and adding more advanced features like autonomous navigation or real-time data analytics would make the system more robust and scalable.`

## 17.4 What Changed From the Original Plan

`We initially planned to run the RFID and Touch sensors on the Arduino. However, due to logic
voltage differences (3.3V vs 5V) and SPI pin conflicts with the Motor Shield, we shifted the
security sensors to the Raspberry Pi. This improved performance and separated the "Security
Hub" from the "Motor Controller".`

# 18. Reflection

## 18.1 Team Reflection

`The team worked well in collaboratively integrating hardware and software components, with clear division of tasks such as coding, circuit setup, and testing. Effective communication helped in quickly resolving minor issues during development. However, progress was occasionally slowed by sensor calibration challenges and integration delays between modules. Overall, time and responsibilities were managed fairly well, though better planning and earlier testing could have improved efficiency and reduced last-minute adjustments.`

## 18.2 Technical Reflection

`Through this project, we gained practical knowledge across multiple domains. In electronics, we learned how to interface sensors, motors, and power systems effectively. In coding, we improved our skills in microcontroller programming and communication between systems like Raspberry Pi and Arduino. Mechanically, we understood how motor selection and chassis design affect movement and stability. In fabrication, we learned basic assembly, wiring, and component placement for reliability. Most importantly, in integration, we realized the challenge of combining all hardware and software modules into a single, smoothly functioning system.`


## 18.3 Design Reflection
 
`Through this project, we learned that good designing is not just about functionality but also about making the system intuitive and user-friendly. We understood the importance of delight in creating engaging experiences, such as smooth control and interactive features. Clarity became essential in both the user interface and system feedback to avoid confusion. Physical interaction taught us how users engage with real-world components like sensors and controls. We also improved our understanding of user behavior through testing, which guided better decisions. Finally, iteration proved crucial, as repeated testing and refinement helped us gradually improve performance, usability, and overall system quality.`

## 18.4 If You Had One More hour

`With one more hour, we would focus on fine-tuning system performance by improving sensor calibration and reducing communication delay between modules. We would also make small but impactful enhancements to the user interface for clearer feedback and smoother control. Additionally, we’d run a quick round of testing to fix minor bugs and ensure more consistent, reliable behavior across all features.`

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


