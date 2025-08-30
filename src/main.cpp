// Sign Glove Project - Arduino Code (3 Flex Sensors + MPU6050)
// Components: Arduino Uno, HC-05 Bluetooth Module, 3 Flex Sensors, MPU6050

#include <Wire.h>
#include <MPU6050_light.h>
#include <SoftwareSerial.h>

#define FLEX1 A0   // Flex Sensor 1
#define FLEX2 A1   // Flex Sensor 2
#define FLEX3 A2   // Flex Sensor 3
#define THRESHOLD 600  // Adjust threshold for sensitivity

SoftwareSerial BTSerial(10, 11);  // RX, TX for HC-05
MPU6050 mpu(Wire);
byte lastCommand = 0xFF;  // Store last command

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.calcOffsets(true);
  pinMode(FLEX1, INPUT);
  pinMode(FLEX2, INPUT);
  pinMode(FLEX3, INPUT);
}

int getStableReading(int pin) {
  int sum = 0;
  for (int i = 0; i < 7; i++) {   // Average 7 readings
    sum += analogRead(pin);
    delay(2);
  }
  return sum / 7;
}

void loop() {
  int flex1 = getStableReading(FLEX1);
  int flex2 = getStableReading(FLEX2);
  int flex3 = getStableReading(FLEX3);

  byte flex1State = (flex1 > THRESHOLD) ? 0b1 : 0b0;
  byte flex2State = (flex2 > THRESHOLD) ? 0b1 : 0b0;
  byte flex3State = (flex3 > THRESHOLD) ? 0b1 : 0b0;
  byte command = (flex3State << 2) | (flex2State << 1) | flex1State;

  String gesture = "";

  switch (command) {
    case 0b000: gesture = "Emergency"; break;
    case 0b001: gesture = "I need water"; break;
    case 0b010: gesture = "I need help"; break;
    case 0b011: gesture = "I am hungry"; break;
    case 0b100: gesture = "Call a doctor"; break;
    case 0b101: gesture = "I am in pain"; break;
    case 0b110: gesture = "I am okay"; break;
  }

  mpu.update();
  float ax = mpu.getAccX();
  float ay = mpu.getAccY();
  float az = mpu.getAccZ();

  if (ax > 1.5) gesture = "Call a nurse";
  else if (ax < -1.5) gesture = "I feel dizzy";
  else if (ay > 1.5) gesture = "Increase room temperature";
  else if (ay < -1.5) gesture = "Decrease room temperature";
  else if (az > 1.5) gesture = "Turn on lights";
  else if (az < -1.5) gesture = "Turn off lights";

  if (gesture != "") {
    Serial.print("COMMAND SENT -> ");
    Serial.println(gesture);
    BTSerial.println(gesture);
  }

  delay(200);
}
