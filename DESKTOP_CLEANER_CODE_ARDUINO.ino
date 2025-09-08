/*
 * Desktop Cleaner Template
 * This code is made by MegaZroN, portfolio https://megazron.com
 * Controls a motor-based cleaning system using an ultrasonic sensor and OLED display.
 * The system activates the motor when an object is within a specified distance.
 * Uses Adafruit SSD1306 library for OLED display.
 * Modify pin assignments, distance thresholds, and display settings as needed.
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Initialize OLED display (modify I2C address if needed)
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin definitions (modify as needed)
int motor1pin1 = 2;  // Motor control pin 1
int motor1pin2 = 3;  // Motor control pin 2
#define echoPin 8    // Ultrasonic sensor echo pin
#define trigPin 9    // Ultrasonic sensor trigger pin

long duration;  // Variable to store pulse duration
int distance;   // Variable to store calculated distance

void setup() {
  // Initialize serial communication (modify baud rate if needed)
  Serial.begin(9600);

  // Initialize OLED display
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Update I2C address if needed
    Serial.println(F("DESKTOP CLEANER allocation failed"));
    while (true);  // Halt if OLED initialization fails
  }

  // Initial display setup
  delay(2000);  // Wait for display to stabilize
  oled.clearDisplay();
  oled.setTextSize(1);       // Set text size
  oled.setTextColor(WHITE);  // Set text color
  oled.setCursor(0, 30);     // Set cursor position
  oled.println("DESKTOP CLEANER");  // Display initial message
  oled.display();

  // Set pin modes
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to centimeters

  // Output distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Update OLED display
  oled.clearDisplay();
  oled.setCursor(0, 30);
  oled.print(distance);
  oled.println(" cm");
  oled.display();

  // Motor control based on distance (modify threshold as needed)
  if (distance <= 15) {  // Activate motor if object is within 15 cm
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    Serial.println("LOW DISTANCE");
    delay(1000);  // Adjust delay as needed
  } else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    Serial.println("HIGH DISTANCE");
    delay(1000);  // Adjust delay as needed
  }
}
