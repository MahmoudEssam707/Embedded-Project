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
// Database child nodes
String IR_path_real = "/Ir_Sensor_4095";
String IR_path_map = "/Ir_Sensor_180";
String timePath = "/timestamp";
// Parent Node (to be updated in every loop)
String parentPath;
int timestamp;
FirebaseJson json;
// Network time Protocl Server
const char *ntpServer = "pool.ntp.org";
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {12,14,27,26};
byte colPins[COLS] = {25,33,32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int IR_PIN = 34;

Servo myServo;

LiquidCrystal_I2C lcd(0x27,16,2);

unsigned long dataMillis = 0;

String readKeypadInput() {
  int i = 0;
  String password = "";
  lcd.setCursor(0, 0);
  lcd.print("Enter password:");
  lcd.setCursor(0, 1);
  while (i < 9) {
    char key = keypad.getKey();
    if (key != NO_KEY) {
      password += key;
      Serial.print(key);
      lcd.print("*");
      i++;
    }
  }
  return password;
}
// Function that gets current epoch time
unsigned long getTime()
{
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return 0;
  }
  time(&now);
  return now;
}

void setup() {
  myServo.attach(13);
  pinMode(IR_PIN, INPUT);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }
  lcd.init();
  lcd.backlight();
  auth.user.email = "mahmoud@gmail.com";
  auth.user.password = readKeypadInput();
  configTime(0, 0, ntpServer);
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
  databasePath = "/UsersData/" + uid + "/readings";
}

void CurrentMode()
{
int result = Firebase.RTDB.getInt(&fbdo, databasePath + "/" + String(timestamp) + timePath);
if (result)
{
    timestamp = result;
    Serial.printf("Get time... %d\n", timestamp);
}
else
{
    Serial.printf("Error getting time: %s\n", fbdo.errorReason().c_str());
}
  int IR_reads = analogRead(IR_PIN);
  int IR_mapped = map(IR_reads,0,4095,0,180);
  if (Firebase.RTDB.setInt(&fbdo, databasePath + "/" + String(timestamp) + IR_path_real, IR_reads) && Firebase.RTDB.setInt(&fbdo, databasePath + "/" + String(timestamp) + IR_path_map, IR_mapped) && Firebase.RTDB.setInt(&fbdo, databasePath + "/" + String(timestamp) + timePath, timestamp))
  {
    if (Firebase.RTDB.getInt(&fbdo, databasePath +IR_path_map))
    {
      int reads_of_IR = fbdo.intData();
      lcd.clear();
      lcd.print("Servo Angle = ");
      lcd.print(reads_of_IR);
      Serial.println(reads_of_IR);
      myServo.write(reads_of_IR);
    }
  }
}
void AppendMode()
{
  int IR_reads = analogRead(IR_PIN);
  int IR_mapped = map(IR_reads, 0, 4095, 0, 180);

  FirebaseJson updateJson;
  updateJson.set(IR_path_real.c_str(), IR_reads);
  updateJson.set(IR_path_map.c_str(), IR_mapped);
  updateJson.set(timePath.c_str(), timestamp);

  // Update the lastAppendedTimestamp node in the database
  String lastNodePath = databasePath + "/" + String(timestamp);
  if (Firebase.RTDB.setJSON(&fbdo, lastNodePath.c_str(), &updateJson))
  {
    Serial.println("Data appended successfully to last node.");
  }
  else
  {
    Serial.println("Error appending data to last node: " + fbdo.errorReason());
  }
}

void DeleteNode() {
    if (Firebase.RTDB.deleteNode(&fbdo, databasePath + "/" + String(timestamp) + timePath)) {
        Serial.printf("Delete node... %s\n", "ok");
    } else {
        Serial.printf("Error deleting node: %s\n", fbdo.errorReason().c_str());
    }
}
void loop()
{
  if (millis() - dataMillis > 200 && Firebase.ready())
  {
    // Get current timestamp
    timestamp = getTime();
    Serial.print("time: ");
    Serial.println(timestamp);
    char key = keypad.getKey();
    if (key)
    {
      switch (key)
      {
      case '1':
        CurrentMode();
        break;
      case '2':
        AppendMode();
        break;
      case '3':
        DeleteNode();
        break;
      default:
        break;
      }
    }
  }
  else
  {
    Serial.println("Firebase Error: " + fbdo.errorReason());
  }
}
