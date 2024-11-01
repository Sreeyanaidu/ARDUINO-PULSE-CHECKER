#include <Adafruit_GFX.h>          // Graphics library for the OLED
#include <Adafruit_SSD1306.h>      // Library for the OLED display
#include <Wire.h>                  // I2C library for communication
#include <PulseSensorPlayground.h> // Library for Pulse Sensor

#define SCREEN_WIDTH 128           // OLED display width, in pixels
#define SCREEN_HEIGHT 64           // OLED display height, in pixels
#define OLED_RESET    -1           // OLED reset pin, -1 if sharing Arduino reset pin

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define PULSE_SENSOR_PIN A0        // Pulse Sensor connected to analog pin A0
#define THRESHOLD 550              // Threshold for detecting a beat (adjust as needed)

// Create an instance of the PulseSensorPlayground library
PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600);

  // Initialize display with I2C address 0x3C for OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED initialization failed"));
    while(true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Pulse Tester");
  display.display();
  delay(1000);

  // Initialize the Pulse Sensor
  pulseSensor.analogInput(PULSE_SENSOR_PIN);
  pulseSensor.setThreshold(THRESHOLD);
  
  if (!pulseSensor.begin()) {
    Serial.println("Pulse Sensor initialization failed");
    while(true);
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute(); // Get BPM value

  // If BPM > 0, we have a valid pulse detected
  if (pulseSensor.sawStartOfBeat()) {
    Serial.print("BPM: ");
    Serial.println(myBPM);

    // Display BPM on OLED
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Pulse Tester");
    display.setTextSize(2);
    display.setCursor(0, 20);
    display.print("BPM: ");
    display.println(myBPM);
    display.display();
  }
}
