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

MBotDCMotor motor_all(all);
MBotDCMotor motor_m1(m1);
MBotDCMotor motor_m2(m2);

MeRGBLed led(led_port, 2);

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
  while (counter < 10) {
    led.setColor(two_leds, 255, 255, 255);
    led.show();
    delay(200);
    led.setColor(two_leds, 0, 0, 0);
    led.show();
    delay(200);
    ++counter;
  }


}

void loop() {

}
