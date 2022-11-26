
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 


Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


int motor1pin1 = 2;
int motor1pin2 = 3;

#define echoPin 8 
#define trigPin 9 


long duration; 
int distance;


void setup() {
   Serial.begin(9600);


  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("DESKTOP CLEANER allocation failed"));
    while (true);
  }

  delay(2000);         
  oled.clearDisplay(); 

  oled.setTextSize(1);       
  oled.setTextColor(WHITE);  
  oled.setCursor(0, 30);     
  oled.println("DESKTOP CLEANER"); 
  oled.display();
  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
 
  
}

void loop() {

   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  oled.println(distance);
   oled.println(" cm");
if (distance <=15)
{  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
   Serial.println("LOW DISTANCE");
    delay(1000);
}
  
else
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
   Serial.println("HIGH DISTANCE");
   delay(1000);
}
 
}