# ARDUINO-PULSE-CHECKER
 This project creates a Pulse Tester using an Arduino Uno, heart rate sensor, and a 0.96" OLED display to measure and display a person’s heart rate in beats per minute (BPM). 
Components Used
Arduino Uno: The main microcontroller that processes sensor readings and controls the OLED display.
Pulse Sensor: A small, wearable device that detects a pulse via blood flow changes, outputting a signal that can be processed to measure BPM.
OLED Display (0.96" I2C): A compact screen used to visually display the BPM data. The I2C communication makes it easy to connect and program with only two data pins (SDA and SCL).
Project Purpose
The purpose of the pulse tester is to measure and display real-time heart rate data. This can be useful for tracking health or fitness progress and offers an introduction to biomedical sensors and real-time data display in Arduino projects.

How It Works
Initialization: When the system starts, the OLED display initializes and shows "Pulse Tester" to confirm that the screen and connections are working.
Pulse Detection:
The Pulse Sensor, connected to an analog input on the Arduino, reads the analog voltage changes caused by blood flow variations with each heartbeat.
The Arduino’s PulseSensorPlayground library interprets these variations and calculates the BPM by counting the pulses within a set period.
A threshold is set to avoid noise in the readings, only registering a pulse when the signal exceeds this limit.
Display BPM:
The system continuously monitors the sensor, and each time a beat is detected, it calculates the current BPM.
The BPM value is printed on the serial monitor and displayed on the OLED screen in real time.
The display is cleared and updated every time a new beat is detected, ensuring that only the current BPM is shown.
Connections Overview
Pulse Sensor:

Signal Pin → Arduino Analog Pin A0
Power (VCC) → Arduino 5V
Ground (GND) → Arduino GND
OLED Display (I2C):

VCC → Arduino 5V
GND → Arduino GND
SCL → Arduino A5 (I2C clock line)
SDA → Arduino A4 (I2C data line)
Code Breakdown
Library Imports:

Adafruit_GFX and Adafruit_SSD1306 for OLED display management.
Wire library for I2C communication with the OLED.
PulseSensorPlayground library to simplify the handling of signals from the Pulse Sensor.
Threshold Setup:

A threshold value of 550 is used to filter out noise, making it easier to detect actual heartbeats.
Display and Sensor Setup:

The display is initialized and tested, showing a starting message.
The Pulse Sensor is set up on analog pin A0 and configured to recognize beats above the set threshold.
Loop Functionality:

Continuously checks for a heartbeat.
If a heartbeat is detected, the BPM is updated on both the serial monitor and the OLED display.
Usage
Run the Code on Arduino Uno with the circuit connected.
Observe the OLED Display to see your pulse rate in BPM.
Adjust Threshold if needed for different individuals or environments with more electrical noise.
Applications
This pulse tester can serve as a simple heart rate monitoring system, suitable for DIY health projects, fitness tracking, or educational purposes in biomedical electronics. It provides hands-on experience with sensor integration, analog signal processing, and real-time data display using microcontrollers.
