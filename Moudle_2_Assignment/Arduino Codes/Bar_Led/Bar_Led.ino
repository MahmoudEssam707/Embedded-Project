#define LED_NUMBER 8
int LED_PINS[LED_NUMBER] = {13, 12, 11, 10, 9, 8, 7, 6};
int POT_PIN = A0;
int NUMBER_OF_LEDS;
void setup() {
  Serial.begin(115200);
  Serial.println("Please put number of leds you want to turn on : ");
  for (int i = 0; i < LED_NUMBER; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
}
void loop() {
  int pot_value = analogRead(POT_PIN); // Read the potentiometer value
  int num_leds_on = map(pot_value, 0, 1023, 0, NUMBER_OF_LEDS); // Map the potentiometer value to a range of 0 to 8
  if(Serial.available() > 0){
     NUMBER_OF_LEDS = Serial.parseInt();
  }
  Serial.println(NUMBER_OF_LEDS);
  for (int i = 0; i < NUMBER_OF_LEDS; i++) {
    if (i < num_leds_on) {
      digitalWrite(LED_PINS[i], HIGH); // Turn on the LED if it should be on
    } else {
      digitalWrite(LED_PINS[i], LOW); // Turn off the LED if it should be off
    }
  }

  delay(50); // Add a short delay to reduce flicker
}
