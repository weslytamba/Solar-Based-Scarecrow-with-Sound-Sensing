#include <Servo.h>
#include "SoftwareSerial.h"

//buzzer
const int buzzer = 8;
//servo
Servo servo;
Servo servo1;
Servo servo2;
//ultrasonic
int trig_pin = 2;
int echo_pin = 3;
long echotime;
float distance;
int pos = 0;

void setup()
{
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    digitalWrite(trig_pin, LOW);
    servo1.attach(9);  
    servo2.attach(10); 
    servo.attach(11);  
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    echotime = pulseIn(echo_pin, HIGH);
    distance = echotime * 0.034 / 2;
    
    if (distance < 25) {
        for (pos = 0; pos < 180; pos += 1) {
            servo1.write(pos);
            servo2.write(pos);
            servo.write(pos);
            digitalWrite(buzzer, HIGH);
            delay(15);
        }
        for (pos = 180; pos >= 1; pos -= 1) {
            servo1.write(pos);
            servo2.write(pos);
            servo.write(pos);
            digitalWrite(buzzer, LOW);
            delay(15);
        }
    }
}