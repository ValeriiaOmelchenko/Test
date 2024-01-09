#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Servo.h>
#include <EEPROM.h>

Servo servo;
const uint8_t EEPROM_ADDRESS = 3;  
uint8_t angle;
uint16_t command;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  }

void loop() {
  if (Serial.available()) {
    command = Serial.parseInt();
    if ((command > 0) && (command < 180)){
      angle=command;
    }
    executeCommand(command);
    delay(100);
  }
}

void executeCommand(int command) {
  switch (command) {
    case 200:
      readAngle();
      break;
    case 300:
      saveAngle(angle);
      break;
    default:
      writeAngle(angle);
      break;
  }
}

void readAngle() {
  angle = EEPROM.read(EEPROM_ADDRESS);
  Serial.println(angle);
}

void writeAngle(uint8_t angle) {
      servo.write(angle);
  }

void saveAngle(uint8_t angle) {
  EEPROM.write(EEPROM_ADDRESS, angle);
}
