# Smart Flower Pot

A PlatformIO + Arduino project that monitors soil moisture and shows the current status on a 128x64 OLED display.

## Overview

This project reads a soil moisture sensor using:

- Analog input on `A3`
- Digital input on `D4`

It then:

- Prints sensor values to the serial monitor
- Shows a clear `WET` or `DRY` status on an SSD1306 OLED display
- Updates once per second

## Hardware

- Arduino Nano (ATmega328P)
- Soil moisture sensor module (analog + digital output)
- SSD1306 OLED display (I2C, 128x64)
- Jumper wires

## Pin Mapping

- Moisture sensor analog output -> `A3`
- Moisture sensor digital output -> `D4`
- OLED I2C address -> `0x3C`

Standard I2C pins on Arduino Nano:

- `A4` = SDA
- `A5` = SCL

## Moisture Logic

In `src/main.cpp`, the status is calculated from the analog value:

- `analogValue < 800` -> `WET`
- `analogValue >= 800` -> `DRY`

You can tune this threshold for your specific sensor and soil type by changing:

- `MOISTURE_THRESHOLD`

## Software Stack

- PlatformIO
- Arduino framework
- `Adafruit SSD1306`
- `Adafruit GFX Library`

## Build and Upload

From the project root:

```bash
pio run
pio run -t upload
```

To open serial monitor:

```bash
pio device monitor
```

## Project Structure

```text
platformio.ini
src/
  main.cpp
include/
lib/
test/
```

## Notes

- The OLED text shows:
  - Large status label (`WET` / `DRY`)
  - Current analog value
  - Current digital value (`D4`)
- Serial output runs at `115200` baud.

## License

No license file is currently included. Add a license if you plan to publish or share this repository publicly.
