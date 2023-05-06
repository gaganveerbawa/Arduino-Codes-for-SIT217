#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// LCD library
LiquidCrystal_I2C lcd(0x27, 16, 2);

int m1 = 4;
int m2 = 5;
int m3 = 6;
int m4 = 7;
int ir = 3;

// Variable for storing bluetooth signal
char bluetoothInput;
bool bluetoothConnected = false;

void setup() {
  // MOtor Pins as Output
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(ir, INPUT);

  // starting Serial Monitor and Lcd
  Serial.begin(9600);
  lcd.begin();

  // Initialize the flag to false
  bluetoothConnected = false;

}

void loop() {

  // Reading Potentiometer Value
  int speedIN = analogRead(A0);
  int speedOUT = speedIN / 4;

  // Writing the speed to the motordriver Speed Pins (ENA) AND (END)
  analogWrite(10, speedOUT);
  analogWrite(11, speedOUT);

  if (bluetoothConnected && digitalRead(ir) == HIGH) {
    // Obstacle detected, stop the car
    stop();
    delay(1000);
    backward();
    delay(1000);
    stop();
    // lcd.print("Obstacle detected");
  } else {

    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // Clearing Screen
      lcd.clear();

      bluetoothConnected = true;
      while (Serial.available()) {
        bluetoothInput = Serial.read();

        switch (bluetoothInput) {
          case 'F':  // Case for Moving Forward
            forward();
            lcd.print("Moving Forward");
            break;

          case 'G':  // Case for Moving Backward
            backward();
            lcd.print("Moving Backward");
            break;

          case 'L':  // Case for Moving Left
            left();
            lcd.print("Moving Left");
            break;

          case 'R':  // Case for Moving Right
            right();
            lcd.print("Moving Right");
            break;

          case 'S':  // Case for Stop
            stop();
            lcd.print("STOPPED");
            break;
        }
      }
    }
  }
}
// car to move forward Function
void forward() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

// car to move backward Function
void backward() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

// car to move left Function
void left() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

// car to move right Function
void right() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

// car to stop Function
void stop() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
