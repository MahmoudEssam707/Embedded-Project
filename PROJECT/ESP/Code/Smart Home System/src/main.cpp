// Needed Libraries
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
// Servo connection
#define SERVO 23
Servo Door;
// Gas connection
#define Gas 34
// Pir motion Connection
#define PIR_MOTION 4
// Flame Sensor Connection
#define Flame_Sensor 35
// Keypad Connection
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte rowPins[ROWS] = {13, 12, 14, 27}; // Change these pins to match your wiring
byte colPins[COLS] = {26,25,33}; // Change these pins to match your wiring
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
// LCD Connection
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(PIR_MOTION, INPUT);
  pinMode(Gas, INPUT);
  pinMode(Flame_Sensor, INPUT);
  Door.attach(SERVO);
  lcd.clear();
  lcd.print("Hello");
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    // Do something with the key, e.g., display it on the LCD
    lcd.clear();
    lcd.print("Key Pressed:");
    lcd.setCursor(0, 1);
    lcd.print(key);
  }
    int motionValue = digitalRead(PIR_MOTION);
    int gasValue = analogRead(Gas);
    int flameValue = analogRead(Flame_Sensor);
    Serial.println(motionValue);
    Serial.println(gasValue);
    Serial.println(flameValue);
    Door.write(70);
    delay(500);
  }