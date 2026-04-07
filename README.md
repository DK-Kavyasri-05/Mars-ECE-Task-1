# MaRS Electronics Subsystem Task 1 Submission

Welcome to my submission repository for the MaRS Robotics Club Electronics Subsystem. This repository contains the source code (`.cpp` files) for Section A and Section B, along with this integrated documentation providing links to my Tinkercad simulations and explanations of the functionality.

---

## 🟢 Section A: Tinkercad Simulation Questions

### Question 1: Blinking LED with different time interval
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/4pJtiBDvWCs-marstask1q1?sharecode=6CN3JmCLxz7X5FDFpi37JVyCDmtXrguMyn8fW0adKaQ)
* **Code File:** `Question_1_Blinking_LED.cpp`
* **Code Logic Explanation:**
In this circuit, three LEDs blink simultaneously but at completely independent intervals (500ms, 1000ms, and 1500ms) without blocking one another. This is achieved by using the non-blocking `millis()` function. The code constantly evaluates the elapsed time for each LED (`currtime - lasttime_x`) against its assigned interval. When the threshold is met, the LED state toggles and the corresponding `lasttime` variable is updated.

### Question 2: Controlling RGB LED and LED Blinking Speed
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/bNPMODNMjM8-marstask1q2?sharecode=MuuJMeQ3s6-Y5WsDwsCzt0CIS_KUQZPRbSrQUkVrKhQ)
* **Code File:** `Question_2_RGB_LED_Potentiometer.cpp`
* **Code Logic Explanation:**
This circuit connects a potentiometer to an analog input (A0). Based on the analog value read (ranging from 0 to 1023), the RGB LED's color shifts between distinct color ranges (Red for <341, Green for 341-681, Blue for >=682). Simultaneously, the blinking interval of a secondary LED is dynamically controlled by using the raw potentiometer value directly as the threshold for the `millis()` comparison, making it blink faster as the value decreases and slower as it increases.

### Question 3: Reaction Time Tester
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/f9fh0nv4hLT-marstask1q3?sharecode=p-kofUQVJRi2i6KelF4zW2EkXY4dW5L1gZJPH4vyypM)
* **Code File:** `Question_3_Reaction_Time_Tester.cpp`
* **Sensor Math & Logic Explanation:**
The system generates a random initial delay (between 2-5 seconds). Once this time elapses, the LED illuminates, and `start_time` is recorded. When the user reacts and pushes the tactile switch (which is configured as an `INPUT_PULLUP`), the current time is grabbed. The reaction mathematics is simply `reaction_time = curr_time - start_time;` where `curr_time` is sampled the instant the button state reads `HIGH`. The result is then broadcasted to the Serial Monitor in milliseconds.

---

## 🚀 Section B: Mini Projects

### Mini Project 1: Smart Distance Alert System (Anti-Slouch/Posture Monitor)
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/3YAXtDE6Ja5-mini-project-1?sharecode=Xn1sH3zeLUuQjDthQNbKvtxwpmOw46znP8qcvWxKOic)
* **Code File:** `Project_Smart_Distance_Alert_System.cpp`
* **What the project does and why I chose it:**
This project actively monitors distance via an ultrasonic sensor and serves as an interactive posture or proximity alarm system. If an object stays inappropriately close (under 30cm) for an extended duration (over 5 seconds without moving back), an alarm trigger physically actuates a vibration motor and dynamically cycles an RGB LED from Cyan to Red. I chose this concept because it perfectly highlights the usage of internal state timers to prevent false positives while remaining continuously vigilant.
* **Components Used:**
   - **Ultrasonic Sensor (HC-SR04):** Bounces acoustic pulses to calculate object distance.
   - **Vibration Motor:** Acts as the tactile feedback mechanism when the time limit gets exceeded.
   - **RGB LED:** Provides a visual status indicating safe (Cyan) versus alert (Red) conditions.
* **Challenges faced and how I solved them:**
One significant hurdle was accurately tracking out-of-bounds duration without freezing the loop using `delay()`. To fix this, I successfully implemented a state machine mapping time differences using `millis()`. This allows the ultrasonic sensor to rapidly scan distances while simultaneously monitoring a 5-second countdown violation.

### Mini Project 2: Smart Auto-Night Lamp & Tilt-Snooze Alarm
* **Tinkercad Link:** [View Simulation](https://www.tinkercad.com/things/98DDkzSdMAs-mini-project-2?sharecode=XATJ_OzKVdsHB0UijKHOZMVUVvFuE4rh_WmtH8f-jBg)
* **Code File:** `Project_Smart_Alarm_System.cpp`
* **What the project does and why I chose it:**
This circuit leverages ambient light detection combined with physical interaction. When ambient light shoots above a specific threshold and the system tilt orientation is undisturbed, a buzzer alarm sequence activates. The built-in push-button functions as a 10-second mute/snooze feature, briefly stalling the cycle. I chose this setup because it cleverly combines an environmental sensor with an orientation-based fail-safe.
* **Components Used:**
   - **LDR (Photoresistor):** Senses the intensity of environmental light.
   - **Tilt Sensor:** Provides a conditional constraint for the alarm behavior—detecting physical orientation.
   - **Piezo Buzzer:** Serves as the auditory alarm signal.
   - **Pushbutton:** Allows the user to interrupt the process using the programmed snooze state.
* **Challenges faced and how I solved them:**
I encountered difficulty integrating the temporary 10-second "snooze" delay because a traditional `delay()` pause would interrupt the continuous monitoring of the tilt sensor and light levels. The solution was applying non-blocking `millis()` tracking wrapped around a distinct boolean variable (`isSnoozed`), permitting seamless transitions back to the sensing polling loop continuously.
