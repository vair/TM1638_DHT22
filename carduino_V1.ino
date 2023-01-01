#include <Servo.h>

Servo servo1;  // create servo object to control a servo
int enablePin = 3;  // enable pin for the motor driver
int in1Pin = 4;  // input 1 pin for the motor driver
int in2Pin = 5;  // input 2 pin for the motor driver

void setup() {
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(enablePin, OUTPUT);  // set the enable pin as an output
  pinMode(in1Pin, OUTPUT);  // set the input 1 pin as an output
  pinMode(in2Pin, OUTPUT);  // set the input 2 pin as an output
  Serial.begin(9600);  // start serial communication at 9600 baud rate
}

void loop() {
  int input = Serial.read();  // read the input from the serial port

  if (input == '1') {  // if the input is '1', move servo 1 to 0 degrees
    servo1.write(0);
  }
  else if (input == '2') {  // if the input is '2', move servo 1 to 180 degrees
    servo1.write(180);
  }
  else if (input == '3') {  // if the input is '3', turn on motor 1 in forward direction at full speed
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
  }
  else if (input == '4') {  // if the input is '4', turn on motor 1 in reverse direction at full speed
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
  }
  else if (input == '5') {  // if the input is '5', turn off motor 1
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    analogWrite(enablePin, 0);  // set the duty cycle to 0 (minimum speed)
  }
}
