# Task 1

This Arduino sketch allows you to control a servo motor by sending angle values through the UART.

### Requirements

- Arduino board
- Servo motor
- [Arduino IDE](https://www.arduino.cc/en/software) installed
- Task1.ino file

### Dependencies

- [Servo Library](https://www.arduino.cc/en/Reference/Servo) (Included in Arduino IDE)

### Installation

1. Connect the servo motor to pin 3 on the Arduino board.
2. Open the Arduino IDE and upload the provided sketch.

## Usage

1. Open the Arduino Serial Monitor (Tools -> Serial Monitor).
2. Enter an angle value between 1 and 179 (This gap is due to the peculiarities of the servo used) and press Enter.
3. The servo motor will move to the specified angle.

## Serial Commands

- Send angle values between 1 and 179 through the Serial Monitor to control the servo motor.

## Circuit Connection

- Servo Signal Wire: Pin 3 on Arduino
- Servo Power Wire: Arduino 5V
- Servo Ground Wire: Arduino GND
  
# Task 2

This project allows you to control a servo motor using an Arduino sketch along with a Python GUI. The Arduino sketch receives commands through the Serial Monitor, while the Python GUI provides a user-friendly interface for sending commands. The following functions have been implemented:
- reading the current angle;
- writing a new angle;
- writing the current angle to the permanent memory


## Arduino Setup

### Requirements

- Arduino board
- Servo motor
- [Arduino IDE](https://www.arduino.cc/en/software) installed
- Task2.ino file

### Dependencies

- [Servo Library](https://www.arduino.cc/en/Reference/Servo) (Included in Arduino IDE)

### Installation

1. Connect the servo motor to pin 3 on the Arduino board.
2. Open the Arduino IDE and upload the provided sketch.

## Python GUI Setup

### Requirements

- Python installed (version 3.x recommended)
- Tkinter library (usually included with Python)
- Task2.py file

### Installation

1. Copy and run the provided Python script.

## Usage

1. Run the Python script to open the GUI.
2. Enter an angle value between 1 and 179 and press the corresponding button.
3. The Arduino will receive the command, and the servo motor will move to the specified angle.

## Serial Commands

- Send specific commands through the Python GUI to control the Arduino:
  - Read Angle: `200`
  - Write Angle: `<angle>` (e.g., `90`)
  - Save Angle: `300`
 
# Additional Task

This Arduino sketch combines manual and automatic servo control based on input from a Python GUI and an ADXL345 accelerometer.

## Requirements

- Arduino board
- Two servo motors
- ADXL345 accelerometer
- [Arduino IDE](https://www.arduino.cc/en/software) installed
- AdditionalTask.ino file

## Circuit Connection

Follow these steps to connect the components:

1. **Servo Motors:**
   - Connect the signal wire of the first servo motor to pin 3.
   - Connect the signal wire of the second servo motor to pin 4.
   - Connect the power and ground wires of both servo motors to the appropriate pins on the BreadBoar by + and - respectively.

2. **ADXL345 Accelerometer:**
   - Connect the SDA pin of the accelerometer to the SDA (data) pin.
   - Connect the SCL pin of the accelerometer to the SCL (clock) pin.
   - Connect the power and ground wires of the accelerometer to the appropriate pins on the  BreadBoar by + and - respectively.

3. **BreadBoar:**
   - Connect + and - to the 5v and gnd pins respectively.

## Dependencies

- [Servo Library](https://www.arduino.cc/en/Reference/Servo) (Included in Arduino IDE)
- [Wire Library](https://www.arduino.cc/en/Reference/Wire) (Included in Arduino IDE)
- [Adafruit ADXL345 Library](https://github.com/adafruit/Adafruit_ADXL345) (Install via Arduino Library Manager)
- [Adafruit Sensor Library](https://github.com/adafruit/Adafruit_Sensor) (Install via Arduino Library Manager)

## Setup

1. Open the `AdditionalTask.ino` file in the Arduino IDE.
2. Install the required libraries if not already installed.
3. Upload the sketch to the Arduino board.
4. Power the Arduino board.
5. Use the provided Python GUI to send commands to the Arduino board through the Serial connection.

## Python GUI Setup

### Requirements

- Python installed (version 3.x recommended)
- Tkinter library (usually included with Python)
- AdditionalTask.py file

### Installation

1. Copy and run the provided Python script.

## Commands

- **Read Angle (`200`):** Read the current saved angle from EEPROM.
- **Save Angle (`300`):** Save the current angle to EEPROM.
- **Write Angle (`<angle>`):** Write the specified angle to the first servo motor.
- **Auto Mode (`400`):** Activate Auto Mode for automatic servo control based on accelerometer data.

## GUI Control

- **Read Angle:** Retrieve and display the current angle.
- **Write Angle:** Set a new angle for the first servo motor.
- **Save Angle:** Save the current angle to EEPROM.
- **Auto Mode:** Enable Auto Mode for automatic servo control based on accelerometer data.

## Usage Examples

1. **Manual Control:**
   - Send `90` to set the first servo motor to a 90-degree angle.

2. **Auto Mode:**
   - Send `400` to activate Auto Mode and let the ADXL345 control the servo angles.


