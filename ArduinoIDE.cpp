#include <LiquidCrystal.h>

// Define pins
const int trigPin = 9;
const int echoPin = 8;
const int buzzerPin = 7;

// Initialize LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Distance:");
  Serial.begin(9600);
}

void loop() 
{
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo pulse duration
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2; // in cm

  // Display on LCD
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm     "); 
  // Clear extra chars

  // Buzzer control based on distance
  if (distance <= 100)
  {
    int beepDelay = map(distance, 0, 100, 50, 1000); 
    // Faster beeps as object gets closer
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    delay(beepDelay);
  } 
  else 
  {
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
