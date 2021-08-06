#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;
const int led1 =  13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;
const int led5 = 9;
const int led6 = 8;
const int led7 = 7;
const int led8 = 6;
const int led9 = 5;
int buttonState = 0;
int peizoPin = 4;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);

  Serial.begin(9600);

  pinMode(buttonPin, INPUT);

  lcd.begin();

}
void loop() {

  buttonState = digitalRead(buttonPin);
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue, DEC);
  delay(500);

  if (sensorValue <= 535)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
  }

  if (sensorValue > 535 && sensorValue < 540 )
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
  }

  if (sensorValue > 540 && sensorValue < 545)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
  }

  if (sensorValue > 545 && sensorValue < 550)
  {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
  }

  if (sensorValue > 550 && sensorValue < 555)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
  }

  if (sensorValue > 555 && sensorValue < 560)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
  }


  if (sensorValue > 560 && sensorValue < 565)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
    lcd.backlight();
    lcd.print("WARNING TOO LOUD");
    lcd.setCursor(0, 1);
    lcd.print("   BE QUITE!!");
    delay(5000);
  }


  if (sensorValue > 565 && sensorValue < 570)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    lcd.clear();
    lcd.backlight();
    lcd.print("WARNING TOO LOUD");
    lcd.setCursor(0, 1);
    lcd.print("   BE QUITE!!");
    delay(5000);
  }


  if (sensorValue > 570 && sensorValue < 575)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, LOW);
    lcd.clear();
    lcd.backlight();
    lcd.print("WARNING TOO LOUD");
    lcd.setCursor(0, 1);
    lcd.print("   BE QUITE!!");
    delay(5000);
  }

  if (sensorValue > 600 && sensorValue < 650)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    lcd.clear();
    lcd.backlight();
    lcd.print("HIGH NOISE LEVEL");
    lcd.setCursor(0, 1);
    lcd.print("  HAS REACHED   ");
    tone(peizoPin, 4000);
    delay(4000);
    noTone(peizoPin);
    delay(4000);
    lcd.clear();


  }

}
