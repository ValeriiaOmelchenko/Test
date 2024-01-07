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

Example:
```plaintext
90
