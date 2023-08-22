#include <Wire.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ESP32Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "MEMO"
#define WIFI_PASSWORD "FCbarcelona2009"
#define API_KEY "AIzaSyDADshUI7Rjw6jynScYy5-6RYRgbZrs9mk"
#define DATABASE_URL "https://fir-visualstudio-d089e-default-rtdb.firebaseio.com/"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
// Variable to save USER UID
String uid;
// Database main path (to be updated in setup with the user UID)
String databasePath;
// Parent Node (to be updated in every loop)
String parentPath;
int timestamp;
FirebaseJson json;
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte rowPins[ROWS] = {12, 14, 27, 26};
byte colPins[COLS] = {25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int IR_PIN = 34;

Servo myServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long dataMillis = 0;

String readKeypadInput()
{
  int i = 0;
  String password = "";
  lcd.setCursor(0, 0);
  lcd.print("Enter password:");
  lcd.setCursor(0, 1);
  while (i < 9)
  {
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
      password += key;
      Serial.print(key);
      lcd.print("*");
      i++;
    }
  }
  return password;
}

void setup()
{
  myServo.attach(13);
  pinMode(IR_PIN, INPUT);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
  }
  lcd.init();
  lcd.backlight();
  auth.user.email = "mahmoud1@gmail.com";
  auth.user.password = readKeypadInput();
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Now start!");
  while ((auth.token.uid) == "")
  {
    Serial.print('.');
    delay(1000);
  }
  // Print user UID
  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.println(uid);
  // Update database path
  databasePath ="/UsersData/"+uid+"/Servo/mapped_reads";
}

void CurrentMode()
{
    if (Firebase.RTDB.getInt(&fbdo, databasePath))
    {
      int reads_of_IR = fbdo.intData();
      Serial.println(Firebase.RTDB.getInt(&fbdo, databasePath));
      lcd.clear();
      lcd.print("Servo Angle = ");
      lcd.print(reads_of_IR);
      Serial.println(reads_of_IR);
      myServo.write(reads_of_IR);
    }
  }

void loop()
{
  if (millis() - dataMillis > 200 && Firebase.ready()){
      CurrentMode();
  }else
  {
    Serial.println("Firebase Error: " + fbdo.errorReason());
  }
}
