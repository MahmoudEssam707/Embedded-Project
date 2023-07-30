#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 23, 5, 18, 19, 21); // Initialize LCD pins
int irPin = 34; // Analog input pin for IR sensor
float distance = 0; // Distance value in mm

void setup() {
  Serial.begin(115200);
  // Initialize the LCD screen
  lcd.begin(16, 2);
}

void loop() {
  // Read the analog value from the IR sensor
  int irValue = analogRead(irPin);
  // Printing values
  Serial.println(irValue);
  // Check if the IR sensor is not connected or has a poor connection
  if (irValue < 10) {
    // Display error message on the LCD screen
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("No input detected,");
      lcd.setCursor(0, 2);
      lcd.print("please connect sensor");
  }else{
    lcd.clear();
    // Map the analog value to a distance value between 1-25 mm
    distance = map(irValue, 0, 4095, 1, 25);
    Serial.println(distance);
    // Display the distance value on the LCD screen
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" mm");
  }
  
  delay(100);
}
