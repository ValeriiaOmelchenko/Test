#include <Servo.h>

Servo servo;
int angle = 0;

void setup() {
    Serial.begin(9600);
    servo.attach(3);
}

void loop() {
    if (Serial.available()) {
        angle = Serial.parseInt();
        if ((angle > 0)&&(angle<180)){
        Serial.println(angle); 
        servo.write(angle);
        }
    }
    delay(1000);
}
