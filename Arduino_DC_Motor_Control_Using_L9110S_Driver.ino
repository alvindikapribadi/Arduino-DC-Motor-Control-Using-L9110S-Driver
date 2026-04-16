/*
  ============================================================
  Project Title : Arduino DC Motor Control Using L9110S Driver
  YouTube       : https://www.youtube.com/channel/UCpfAZXTqOsfymN9km-hLfFQ
  ============================================================

  Description:
  This project demonstrates how to control a DC motor using
  the L9110S motor driver module with Arduino.
  The motor will rotate forward, stop, reverse, and stop again.

  Components:
  - Arduino Uno / Nano
  - L9110S Motor Driver Module
  - DC Motor
  - Jumper Wires

  Wiring:
  L9110S -> Arduino
  A-1A  -> D5
  A-1B  -> D6

  L9110S -> Motor
  OA    -> Motor +
  OB    -> Motor -

  Power:
  VCC   -> 5V
  GND   -> GND

  ============================================================
*/

const int motorPinA = 5; // L9110S A-1A
const int motorPinB = 6; // L9110S A-1B

// ===================== SETUP =====================
void setup() {
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);

  stopMotor(); // Ensure motor is stopped at start
}

// ===================== LOOP =====================
void loop() {

  moveForward();
  delay(3000);

  stopMotor();
  delay(2000);

  moveBackward();
  delay(3000);

  stopMotor();
  delay(2000);
}

// ===================== FUNCTIONS =====================

// Rotate motor forward
void moveForward() {
  digitalWrite(motorPinA, HIGH);
  digitalWrite(motorPinB, LOW);
}

// Rotate motor backward
void moveBackward() {
  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, HIGH);
}

// Stop motor
void stopMotor() {
  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, LOW);
}