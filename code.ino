#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  // (I2C address, columns, rows)

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo
Servo doorLockServo;

// Pins
const int tempPin = A0;
const int lightSensorPin = A1;
const int servopin = A2;
const int doorLedPin = 12;
const int buzzerPin = 13;
const int lightLedPin = 10;
const int fanLedPin = 11;

// Password
String password = "1234";
String inputPassword = "";
bool doorUnlocked = false;
int wrongAttempts = 0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  doorLockServo.attach(servopin);
  doorLockServo.write(0); // 🔥 Keep door LOCKED initially!

  pinMode(lightLedPin, OUTPUT);
  pinMode(fanLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(doorLedPin, OUTPUT);

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print("Welcome Guest!");
  delay(2000);

  lcd.clear();
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // Confirm password
      if (inputPassword == password) {
        lcd.clear();
        lcd.print("Access Granted");
        doorUnlock();

        // Play welcome music
        playWelcomeMusic();

        delay(2000);
        lcd.clear();
        lcd.print("Good Day!");
        delay(2000);
        lcd.clear();
      }
      else {
        wrongAttempts++;
        lcd.clear();
        if (wrongAttempts == 1) {
          lcd.print("Wrong Try Again");
          delay(2000);
          lcd.clear();
          lcd.print("Enter Password:");
        }
        else {
          lcd.print("Wrong Password");
          tone(buzzerPin, 1000, 1000); // Beep
          delay(2000);
          lcd.clear();
          lcd.print("Enter Password:");
        }
        inputPassword = "";
      }
    }
    else if (key == '*') { // Reset input
      inputPassword = "";
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else {
      inputPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }
  }

  // After unlock, sensors start working
  if (doorUnlocked) {
    monitorTemperature();
    monitorLight();
  }
}

// Functions

void doorUnlock() {
  doorLockServo.write(90); // 🔥 Unlock position
  digitalWrite(doorLedPin, HIGH);
  doorUnlocked = true;
}

void playWelcomeMusic() {
  tone(buzzerPin, 262, 300);
  delay(300);
  tone(buzzerPin, 294, 300);
  delay(300);
  tone(buzzerPin, 330, 300);
  delay(300);
  noTone(buzzerPin);
}

void monitorTemperature() {
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperatureC, 1);
  lcd.print("C  ");

  if (temperatureC > 30) {
    digitalWrite(fanLedPin, HIGH);
  } else {
    digitalWrite(fanLedPin, LOW);
  }
}

void monitorLight() {
  int lightValue = analogRead(lightSensorPin);

  lcd.setCursor(0, 1);
  lcd.print("Light:");
  lcd.print(lightValue);

  if (lightValue < 500) { // Dark
    digitalWrite(lightLedPin, HIGH);
  } else {
    digitalWrite(lightLedPin, LOW);
  }
}
