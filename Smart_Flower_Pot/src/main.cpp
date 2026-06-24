#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

constexpr int MOISTURE_ANALOG_PIN = A3;
constexpr int MOISTURE_DIGITAL_PIN = 4;
constexpr int MOISTURE_THRESHOLD = 800;
constexpr int SCREEN_WIDTH = 128;
constexpr int SCREEN_HEIGHT = 64;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(MOISTURE_DIGITAL_PIN, INPUT);

  Wire.begin();
  Wire.setClock(100000);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (true) {
      delay(1000);
    }
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  const int analogValue = analogRead(MOISTURE_ANALOG_PIN);
  const int digitalValue = digitalRead(MOISTURE_DIGITAL_PIN);
  const char *moistureStatus = analogValue < MOISTURE_THRESHOLD ? "WET" : "DRY";

  Serial.print("Moisture analog: ");
  Serial.print(analogValue);
  Serial.print(" | digital: ");
  Serial.println(digitalValue);
  Serial.print("Status: ");
  Serial.println(moistureStatus);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);

  display.setCursor(0, 0);
  display.setTextSize(3);
  display.println(moistureStatus);

  display.setTextSize(1);
  display.setCursor(0, 44);
  display.print("Value: ");
  display.println(analogValue);

  display.setCursor(0, 54);
  display.print("D4: ");
  display.println(digitalValue);

  display.display();

  delay(1000);
}