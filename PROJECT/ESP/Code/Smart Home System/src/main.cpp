#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_AHTX0.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD with the I2C address
Adafruit_AHTX0 aht;

void setup()
{
  Serial.begin(115200);
  Serial.println("AHT21 and LCD demo!");

  lcd.init();
  lcd.backlight();

  if (!aht.begin())
  {
    Serial.println("Could not find AHT21. Check wiring.");
    while (1)
      delay(10);
  }
  Serial.println("AHT21 found.");
}

void loop()
{
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp.temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity.relative_humidity);
  lcd.print("% rH");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println("% rH");

  delay(1000);
}
