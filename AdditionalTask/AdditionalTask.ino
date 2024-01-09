#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Servo.h>
#include <EEPROM.h>

Servo servo1;
Servo servo2;
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

const uint8_t EEPROM_ADDRESS = 3;
uint8_t angle;
uint16_t command;
bool autoFlag = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(4);
  if (!accel.begin()) {
    Serial.println("ADXL345 isn`t allowed!");
    while (1)
      ;
  }
}

void loop() {
  if (Serial.available()) {
    command = Serial.parseInt();
    if ((command > 0) && (command < 180)) {
      angle = command;
    }
    if (command < 400) {
      autoFlag = 0;
      executeCommand(command);
    } else {
      autoFlag = 1;
    }
  }
  while (autoFlag) {
    autoADXL();
    if (Serial.available()) {
      command = Serial.parseInt();
      if ((command > 0) && (command < 400))
        break;
    }
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
  servo1.write(angle);
}

void saveAngle(uint8_t angle) {
  EEPROM.write(EEPROM_ADDRESS, angle);
}

void autoADXL() {
  sensors_event_t event;
  accel.getEvent(&event);

  float roll = atan2(event.acceleration.y, event.acceleration.z) * 180 / PI;
  float pitch = atan2(-event.acceleration.x, sqrt(event.acceleration.y * event.acceleration.y + event.acceleration.z * event.acceleration.z)) * 180 / PI;

  uint8_t rollAngle = map(roll, -180, 180, 1, 179);
  uint8_t pitchAngle = map(pitch, -180, 180, 1, 179);

  rollAngle = constrain(rollAngle, 1, 179);
  pitchAngle = constrain(pitchAngle, 1, 179);

  Serial.print(rollAngle);
  Serial.print("\t");
  Serial.println(pitchAngle);

  servo1.write(rollAngle);
  servo2.write(pitchAngle);
}
