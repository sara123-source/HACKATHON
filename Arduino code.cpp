
#define BLYNK_TEMPLATE_ID "TMPL3XaP2WpsY"
#define BLYNK_TEMPLATE_NAME "IOT based IV Drip Monitor"
#define BLYNK_AUTH_TOKEN "NS_nzoIapngALSbIfMJ8SMiN_PaIhg81"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define BUZZER_PIN 14
#define SERVO_PIN 13

Servo servo;
Adafruit_SSD1306 display(128, 64, &Wire, -1);


// WiFi credentials
char ssid[] = "SARAi15";
char pass[] = "saransh123";

// Logic variablesQQ
float totalCapacity = 981.0; // ml
float fluidLevel = 100.0;    // simulate starting fluid level
float minThreshold = 20.0;   // alert level
bool alertTriggered = false;
bool servoMoved = false;

// Buzzer logic
unsigned long lastBuzzerTime = 0;
bool buzzerOn = false;
bool startBeeping = false;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  servo.attach(SERVO_PIN);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("IV Monitor Booting...");
  display.display();
  delay(1500);
}

void loop() {
  Blynk.run();

  // Simulate fluid level decreasing randomly
  fluidLevel -= random(1, 5); // decrease 1 to 4 ml randomly
  if (fluidLevel < 0) fluidLevel = 0;

  float percentage = (fluidLevel / totalCapacity) * 100.0;

  // OLED Display
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("IV: ");
  display.print(fluidLevel, 0);
  display.println("ml");

  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("Level: ");
  display.print(percentage, 1);
  display.println("%");

  if (fluidLevel < minThreshold) {
    display.setCursor(0, 55);
    display.setTextColor(SSD1306_WHITE);
    display.println("ATTENTION: LOW FLUID!");
    startBeeping = true;

    if (!alertTriggered) {
      rotateServoOnce();
      alertTriggered = true;
    }
  }

  display.display();

  // Send to Blynk
  Blynk.virtualWrite(V0, percentage);

  // Handle buzzer beep
  handleBuzzerBeep();

  delay(2000); // 2 seconds delay for smoother simulation
}

void rotateServoOnce() {
  if (!servoMoved) {
    Serial.println("Rotating servo...");
    servo.write(180);
    delay(1000);
    servo.write(0);
    delay(1000);
    servoMoved = true;
  }
}

void handleBuzzerBeep() {
  if (startBeeping) {
    unsigned long currentTime = millis();
    if (currentTime - lastBuzzerTime >= 2000) {
      buzzerOn = !buzzerOn;
      digitalWrite(BUZZER_PIN, buzzerOn ? HIGH : LOW);
      lastBuzzerTime = currentTime;
      Serial.println(buzzerOn ? "Buzzer ON" : "Buzzer OFF");
    }
  }
}