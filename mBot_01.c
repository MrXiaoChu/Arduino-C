#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMCore.h>

#define all 0
#define m1 9
#define m2 10
#define go_front 1
#define go_back 2
#define go_left 3
#define go_right 4

MBotDCMotor motor_all(all);
MBotDCMotor motor_m1(m1);
MBotDCMotor motor_m2(m2);

void setup() {
  
  motor_m1.run(-255);
  delay(500);
  motor_m1.run(0);
  motor_m2.run(-255);
  delay(500);
  motor_m2.run(0);
  motor_m2.run(255);
  delay(500);
  motor_m2.run(0);
  motor_m1.run(255);
  delay(500);
  motor_m1.run(0);

  motor_all.move(go_left, 255);
  delay(200);
  motor_all.move(go_right, 255);
  delay(200);
  motor_all.move(go_front, 0);

  motor_all.move(go_left, 255);
  delay(200);
  motor_all.move(go_right, 255);
  delay(200);
  motor_all.move(go_front, 0);

  motor_all.move(go_left, 255);
  delay(200);
  motor_all.move(go_right, 255);
  delay(200);
  motor_all.move(go_front, 0);

  motor_all.move(go_left, 255);
  delay(200);
  motor_all.move(go_right, 255);
  delay(200);
  motor_all.move(go_front, 0);
  
  motor_all.move(go_left, 255);
  delay(200);
  motor_all.move(go_right, 255);
  delay(200);
  motor_all.move(go_front, 0);
  
}

void loop() {



}
