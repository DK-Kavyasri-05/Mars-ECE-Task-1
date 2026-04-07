# MaRS Electronics Subsystem Task 1 Submission

This is my submission for the MaRS Robotics Club Electronics Subsystem task. Inside this repository you will find the code files for both Section A and Section B, organized into folders. Below are the explanations for each circuit along with the Tinkercad simulation links.

## Section A: Tinkercad Simulation Questions

### Question 1: Blinking LED with different time interval
Tinkercad Link: https://www.tinkercad.com/things/4pJtiBDvWCs-marstask1q1?sharecode=6CN3JmCLxz7X5FDFpi37JVyCDmtXrguMyn8fW0adKaQ

Code File: Section A/Question_1_Blinking_LED.cpp

How the circuit works:
In this circuit, I made three LEDs blink at different intervals (500ms, 1000ms, and 1500ms). I realized early on that I couldn't just use the standard delay function because it would pause the whole program and mess up the other LEDs. Instead, I used the millis tracking method. This lets the arduino keep running the loop while each LED independently checks if enough time has passed to change its state.

### Question 2: Controlling RGB LED and LED Blinking Speed
Tinkercad Link: https://www.tinkercad.com/things/bNPMODNMjM8-marstask1q2?sharecode=MuuJMeQ3s6-Y5WsDwsCzt0CIS_KUQZPRbSrQUkVrKhQ

Code File: Section A/Question_2_RGB_LED_Potentiometer.cpp

How the circuit works:
I connected a potentiometer to an analog pin which gives readings from 0 to 1023 as you twist it. Depending on this reading, I split it into three ranges to change the color of the RGB LED to either red, green, or blue. At the exact same time, I used that raw analog reading to dynamically set the blinking delay for another standard LED using millis. So, the blinking speed visually changes as you turn the knob.

### Question 3: Reaction Time Tester
Tinkercad Link: https://www.tinkercad.com/things/f9fh0nv4hLT-marstask1q3?sharecode=p-kofUQVJRi2i6KelF4zW2EkXY4dW5L1gZJPH4vyypM

Code File: Section A/Question_3_Reaction_Time_Tester.cpp

Sensor Math and Logic:
To make the reaction test unpredictable, I used an unconnected analog pin to generate noise and create a random delay between 2 and 5 seconds. Once that delay time is over, the LED turns on and I save that exact start time. When the user reacts and presses the pushbutton, I log the current time again and simply subtract the start time to get the final reaction time. The time is then printed to the serial monitor.

## Section B: Mini Projects

### Mini Project 1: Smart Posture Monitor
Tinkercad Link: https://www.tinkercad.com/things/3YAXtDE6Ja5-mini-project-1?sharecode=Xn1sH3zeLUuQjDthQNbKvtxwpmOw46znP8qcvWxKOic

Code File: Section B/Project_Smart_Distance_Alert_System.cpp

What the project does and why I chose it:
I built an anti-slouch posture monitor because bad posture is a huge problem for students studying for hours, and I wanted to make something practically useful. If a person gets closer than 30cm to the screen, the system waits to see if they stay there. It only alerts them if they slouch for too long. I used millis instead of the delay tool to achieve this countdown, because an actual delay would completely freeze the sensor from taking new distance readings. By using millis, I could track how long they have been slouching continuously while still checking the distance the whole time.

Components used:
I used an ultrasonic sensor to mathematically measure the distance, a vibration motor for physical feedback, and an RGB LED to show the safe or alert status visually.

### Mini Project 2: Smart Tilt-Snooze Alarm
Tinkercad Link: https://www.tinkercad.com/things/98DDkzSdMAs-mini-project-2?sharecode=XATJ_OzKVdsHB0UijKHOZMVUVvFuE4rh_WmtH8f-jBg

Code File: Section B/Project_Smart_Alarm_System.cpp

What the project does and why I chose it:
This project is an alarm setup that reacts to room light levels and physical orientation. It uses an LDR to trigger a loud buzzer when the sunlight goes above a certain level. But if you tilt the device over, the alarm stops. You can also press a push button to snooze it for 10 seconds. I chose this because it was a fun challenge to combine light sensors with physical tilt changes into one device idea. To handle the 10-second snooze, I used millis instead of an actual delay command because freezing the board would stop the LDR and tilt sensor from working during the snooze time. Using millis let me simply bypass the buzzer while keeping all the sensors running.

Components used:
I used an LDR photoresistor to detect light intensity, a tilt sensor to check if the alarm has been physically knocked over, a piezo buzzer for the alarm sound, and a basic pushbutton for the snooze feature.
