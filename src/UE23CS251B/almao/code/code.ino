#define Trig_Pin 9
#define Echo_Pin 10
#define LED_Pin 13  

unsigned long lastAlarmTime;
const long alarmInterval = 10000;  // 10-second alarm cycle
bool alarmActive = false;

unsigned long lastBlinkTime = 0;
const long blinkInterval = 200;

void setup() {
  Serial.begin(9600);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(LED_Pin, OUTPUT);
  
  lastAlarmTime = millis();
  Serial.println("[INFO]: \"System initialized\"");
}

void loop() {
  unsigned long currentMillis = millis();

  // Trigger alarm cycle every 10 seconds if inactive
  if (currentMillis - lastAlarmTime >= alarmInterval && !alarmActive) {
    alarmActive = true;
    Serial.println("[ALARM]: \"Activated\"");
  }

  // If alarm is active, check sensor and blink LED
  if (alarmActive) {
    float dist = getDistance();
    
    // Send distance as [SENSOR] data
    Serial.print("[SENSOR]: ");
    Serial.println(dist);

    if (dist >= 400 || dist <= 2) {  
      Serial.println("[INFO]: \"Out of range, Alarm continues\"");
    } else {
      Serial.println("[INFO]: \"User detected, Alarm stopped\"");
      alarmActive = false;  
      lastAlarmTime = millis();  
      digitalWrite(LED_Pin, LOW);
    }

    // Blink LED without blocking
    if (currentMillis - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = currentMillis;
      digitalWrite(LED_Pin, !digitalRead(LED_Pin));
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
