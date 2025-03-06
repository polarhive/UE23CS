#define Trig_Pin 9
#define Echo_Pin 10
#define LED_Pin 13  

unsigned long lastAlarmTime;
const long alarmInterval = 10000;  // 10-second alarm cycle
bool alarmActive = false;  // Tracks if alarm is active

unsigned long lastBlinkTime = 0;
const long blinkInterval = 200;  // LED blink every 200ms

void setup() {
  Serial.begin(9600);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(LED_Pin, OUTPUT);
  lastAlarmTime = millis();  // Set initial time for first alarm
}

void loop() {
  unsigned long currentMillis = millis();

  // Start the alarm every 10 seconds after user wakes up
  if (currentMillis - lastAlarmTime >= alarmInterval && !alarmActive) {
    alarmActive = true;
    Serial.println("ALARM! Wake up!");
  }

  // If alarm is active, check sensor and blink LED asynchronously
  if (alarmActive) {
    float dist = getDistance();  // Get user distance

    Serial.print("Distance = ");
    if (dist >= 400 || dist <= 2) {  
      Serial.println("Out of range, Alarm continues...");
    } else {  
      Serial.print(dist);
      Serial.println(" cm - User detected! Alarm stopped.");
      alarmActive = false;  // Stop alarm
      lastAlarmTime = millis();  // Reset timer for next alarm cycle
      digitalWrite(LED_Pin, LOW);  // Ensure LED is off
    }

    // Blink LED without blocking
    if (currentMillis - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = currentMillis;
      digitalWrite(LED_Pin, !digitalRead(LED_Pin));  // Toggle LED
    }
  }
}

// Function to get distance from the ultrasonic sensor
float getDistance() {
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);

  float dur = pulseIn(Echo_Pin, HIGH);
  return (dur / 2) * 0.0343;  // Convert time to distance
}
