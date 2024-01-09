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

## Circuit Connection

- Servo Signal Wire: Pin 3 on Arduino
- Servo Power Wire: Arduino 5V
- Servo Ground Wire: Arduino GND

