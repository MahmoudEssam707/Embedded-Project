#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <ESP32Servo.h>
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
//Define the API key
#define API_KEY "AIzaSyDMs7hmxYQxzZjCTKeub2faE9JsOanQ4YQ"
/* If work with RTDB, define the RTDB URL */
#define DATABASE_URL "https://first-assignment-in-cloud-default-rtdb.firebaseio.com/"
/*Define the Firebase Data object */
FirebaseData fbdo;
/*Define the FirebaseAuth data for authentication data */
FirebaseAuth auth;
/*Define the FirebaseConfig data for config data */
FirebaseConfig config;
// Delaying time
unsigned long dataMillis = 0;
// Define your keypad configuration
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {22, 23, 4, 5};
byte colPins[COLS] = {18, 19, 21};
// Keypad Deceleration
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
// LCD Declearing
LiquidCrystal lcd(13, 12, 14, 27, 26, 25);
// Checking if Auth True will continue, Else won't work
String readKeypadInput() {
    int i = 0;
    String password = "";
    while (i < 9) {
        char key = keypad.getKey();
        if (key != NO_KEY) {
            password += key;
            lcd.print("*");
            i++;
            delay(15);
        }
    } 
    return password;
}

String password = readKeypadInput();
// Declearing IR SENSOR 
const int IR_PIN = 35;
Servo myServo;
void setup()
{
    myServo.attach(33);
    pinMode(IR_PIN, INPUT);
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    lcd.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
    /* Assign the api key (required) */
    config.api_key = API_KEY;
    /* Assign the user sign in credentials */
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Please Wait ...");
    auth.user.email = "mahmoud@gmail.com";
    auth.user.password = password;
    config.database_url = DATABASE_URL;
    Firebase.reconnectWiFi(true);
    fbdo.setResponseSize(4096);
    /* Assign the callback function for the long running token generation task */
    config.token_status_callback = tokenStatusCallback;
    /* Initialize the library with the Firebase authen and config */
    Firebase.begin(&config, &auth);
}
void loop() {
    if (millis() - dataMillis > 101 && Firebase.ready()) {
        // Read analog data from an IR sensor
        int IR_reads = analogRead(IR_PIN);
        // Map the analog readings to a 0-180 range
        int IR_mapped = map(IR_reads, 0, 4095, 0, 180);
        
        // Check if setting data in Firebase is successful
        if (Firebase.RTDB.setInt(&fbdo, "IR/Real_Reads", IR_reads) && Firebase.RTDB.setInt(&fbdo, "IR/Mapped_Reads", IR_mapped)) {
            // Check if getting data from Firebase is successful
            if (Firebase.RTDB.getInt(&fbdo, "/IR/Mapped_Reads")) {
                // Reading Data from Firebase
                int reads_of_IR = fbdo.intData();
                
                // Display the value on an LCD and Serial Monitor
                lcd.clear();
                lcd.println("Servo Angle =" + String(reads_of_IR));
                Serial.println(reads_of_IR);
                // Control a servo motor based on the Firebase data
                myServo.write(reads_of_IR);
                if (reads_of_IR > 90) {
                    digitalWrite(LED_BUILTIN, HIGH);
                } else {
                    digitalWrite(LED_BUILTIN, LOW);
                }            
                } else {
                Serial.println("Firebase Error: " + fbdo.errorReason());
            }
        }
    }
}
