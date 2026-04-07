# MaRS Electronics Subsystem Task 1 Submission

Welcome to my submission repository for the MaRS Robotics Club Electronics Subsystem. This repository contains the source code (`.cpp` files) for Section A and Section B, along with this integrated documentation providing links to my Tinkercad simulations and detailed technical explanations of the internal logic and functionality.

---

## 🟢 Section A: Tinkercad Simulation Questions

### Question 1: Blinking LED with different time interval
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/4pJtiBDvWCs-marstask1q1?sharecode=6CN3JmCLxz7X5FDFpi37JVyCDmtXrguMyn8fW0adKaQ)
* **Code File:** `Question_1_Blinking_LED.cpp`
* **Code Logic Explanation:**
In this circuit, I configured three separate LEDs to blink independently at intervals of 500ms, 1000ms, and 1500ms. If I had used the standard `delay()` function, the entire script would pause, breaking the independent timing sequences because `delay()` blocks the microcontroller from executing other tasks. Instead, I utilized the core timer function, `millis()`. By constantly capturing the elapsed system time (`unsigned long int currtime = millis();`) and finding the delta against each LED's previous stamp (`currtime - lasttime_x`), I effectively created three independent, non-blocking asynchronous timers. 

### Question 2: Controlling RGB LED and LED Blinking Speed
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/bNPMODNMjM8-marstask1q2?sharecode=MuuJMeQ3s6-Y5WsDwsCzt0CIS_KUQZPRbSrQUkVrKhQ)
* **Code File:** `Question_2_RGB_LED_Potentiometer.cpp`
* **Code Logic Explanation:**
This task effectively demonstrates the bridging of Analog-to-Digital Conversion (ADC) and Pulse Width Modulation (PWM). A potentiometer acts as a variable voltage divider connected to the `A0` pin. The Arduino reads this voltage and converts it to an integer from `0` to `1023`. 
I split this range into three equal sectors (0-340, 341-681, 682-1023). Using nested conditional statements, the code checks the sector and triggers `analogWrite()` (PWM) to force the RGB LED into distinct Solid Red, Solid Green, or Solid Blue states. At the same time, this raw ADC reading value (`0-1023`) is dynamically fed right into a `millis()` timer logic gate. Because the value represents milliseconds, twisting the potentiometer simultaneously dictates the exact blinking delay of a secondary standard LED—making it visibly flicker faster or slower based on the knob's position.

### Question 3: Reaction Time Tester
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/f9fh0nv4hLT-marstask1q3?sharecode=p-kofUQVJRi2i6KelF4zW2EkXY4dW5L1gZJPH4vyypM)
* **Code File:** `Question_3_Reaction_Time_Tester.cpp`
* **Sensor Math & Logic Explanation:**
The tester required unpredictability to genuinely assess a user's reaction. To achieve random timing, I seeded the random number generator `randomSeed(analogRead(A0))` using the ambient electronic noise of an unconnected analog pin. A random baseline delay between 2,000 to 5,000 milliseconds is generated. 
The tactile button uses the internal pull-up resistor (`INPUT_PULLUP`). When the LED abruptly triggers, `start_time` is locked. When the user successfully interrupts the circuit by pressing the button (`HIGH`), `curr_time` is sampled. The core math applied is essentially measuring the delta: `reaction_time = curr_time - start_time`. The result is pushed to the Serial port in milliseconds, providing an instant score.

---

## 🚀 Section B: Mini Projects

### Mini Project 1: Smart Distance Alert System (Anti-Slouch/Posture Monitor)
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/3YAXtDE6Ja5-mini-project-1?sharecode=Xn1sH3zeLUuQjDthQNbKvtxwpmOw46znP8qcvWxKOic)
* **Code File:** `Project_Smart_Distance_Alert_System.cpp`

* **What the project does and why I chose it:**
This project continuously broadcasts ultrasonic sound pulses to measure physical distance and dynamically alerts users when they sit unhealthily close to their workspace/screen. I specifically chose to build an Anti-Slouch monitor because it directly tackles a common real-world physiological hazard—poor desk posture—using highly accessible robotics principles. 
Beyond simple distance tracking, I wanted the profound challenge of incorporating an **extended-duration threshold constraint**. Simply triggering an alarm the millisecond someone leans closely is annoying and leads to false positives. So, my goal was to make the system highly intelligent: it visually tracks your distance, but the alarm (vibrator and solid red LED) only initiates if you break the 30cm safety margin continuously for an unyielding 5-second timeframe without correcting your posture. 

* **Components Used:**
   - **Ultrasonic Sensor (HC-SR04):** Operates on acoustic echoes to calculate exact distance metrics.
   - **Vibration Motor / Actuator:** Acts as the physical tactile-feedback mechanism when posture goes out of bounds.
   - **RGB LED:** Provides a gradient visual status (Cyan implies safe operation, Solid Red implies critical posture failure).

* **Challenges faced and how I solved them:**
The most significant hurdle was mapping the 5-second timer without breaking the loop execution. Because the `HC-SR04` ultrasonic sensor needs to constantly poll the current distance multiple times a second, applying a simplistic `delay(5000)` would freeze the entire sensor network, leaving the microcontroller completely "blind". To resolve this, I engineered a logic state machine tied directly to `millis()`. When `distance < 30` drops true for the very first time, a boolean `isSlouching` flags `true` and records a specific timestamp `slouchStartTime`. Until `millis() - slouchStartTime > 5000` evaluates to true, the sensor is completely free to keep tracking user movement and instantly abort the timeout if the user steps back (resetting `isSlouching = false`).

---

### Mini Project 2: Smart Auto-Night Lamp & Tilt-Snooze Alarm
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/98DDkzSdMAs-mini-project-2?sharecode=XATJ_OzKVdsHB0UijKHOZMVUVvFuE4rh_WmtH8f-jBg)
* **Code File:** `Project_Smart_Alarm_System.cpp`

* **What the project does and why I chose it:**
This circuit leverages advanced dual-sensor environmental detection combined with direct physical interaction. When the ambient room light shoots above a calibrated threshold, and the main system chassis' orientation remains undisturbed (untilted), an aggressive buzzer sequences upward. By physically depressing the tactile 'snooze' button, the system goes dormant for exactly 10 seconds.
I specifically chose this project because it simulates the architecture of a complete, premium consumer product. I envisioned an alarm clock that functions via environmental factors—sounding off when the sun shines through the window (increasing the localized LDR values), but turning off completely and instantly if the groggy user accidentally knocks it over on their bedside table (triggering the tilt sensor). This fuses audio-feedback protocols, physical state-disruption, and environmental baseline thresholds entirely into one unified framework. 

* **Components Used:**
   - **LDR (Photoresistor):** Sensitively measures the intensity of environmental luminance dynamically.
   - **Tilt Sensor / Orientation Switch:** A physical restraint ensuring the alarm acts contextually depending on vertical orientation.
   - **Piezoelectric Buzzer:** Serves as the auditory wake-up sequence mechanism.
   - **Pushbutton:** Grants explicit user override via a programmed electronic 'snooze' state.

* **Challenges faced and how I solved them:**
My primary challenge in this project came when implementing the 10-second mute/snooze feature. A hardcoded boolean or basic `delay(10000)` pause would once again fatally interrupt the crucial background polling of both the tilt parameters and the changing LDR values. By relying heavily on non-blocking chronological indexing via `snoozeTime = millis()`, I successfully bridged a temporary override around the entire buzzer logic block (`!isSnoozed`). This permits seamless transitionings in and out of the sensing subroutines flawlessly, irrespective of what the user is currently doing with the hardware.
