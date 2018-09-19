#include <stdio.h>
#include <stdlib.h>
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
#define led_port 7
#define two_leds 0
#define follower_connect_port 4
#define uts_port 1

MBotDCMotor motor_all(all);
MBotDCMotor motor_m1(m1);
MBotDCMotor motor_m2(m2);

MeRGBLed led(led_port, 2);

MeLineFollower lfer(follower_connect_port);

MeUltrasonicSensor uts(uts_port);

int distance;

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

  led.setColor(two_leds, 255, 0, 0);
  led.show();
  delay(1000);
  led.setColor(two_leds, 0, 0, 0);
  led.show();
  led.setColor(two_leds, 0, 255, 0);
  led.show();
  delay(1000);
  led.setColor(two_leds, 0, 0, 0);
  led.show();
  led.setColor(two_leds, 0, 0, 255);
  led.show();
  delay(1000);
  led.setColor(two_leds, 0, 0, 0);
  led.show();

  int counter = 0;
  while (counter < 3) {
    led.setColor(two_leds, 255, 255, 255);
    led.show();
    delay(200);
    led.setColor(two_leds, 0, 0, 0);
    led.show();
    delay(200);
    ++counter;
  }

  Serial.begin(115200);

}

void loop() {

  distance = uts.distanceCm();
  Serial.println(distance);
  switch (distance / 10) {
    case 0:
      Serial.println("close");
      break;
    case 1:
      Serial.println("ok");
      break;
    default:
      Serial.println("far");
  }
  delay(500);
  if (distance < 10) {
    motor_all.move(go_back, 255);

  } else if (distance < 20) {
    int  a = (rand() % 10);
    if (a > 4) {
      motor_all.move(go_left, 255);
      delay(3000);
    } else {
      motor_all.move(go_right, 255);
      delay(3000);
    }
    motor_all.move(go_front, 0);
  } else {
    motor_all.move(go_front, 255);
  }

}
