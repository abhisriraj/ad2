#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int redLed = 7;
int greenLed = 6;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 120;


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1,0);
    lcd.print("JAKIR HOSSAIN");
    lcd.setCursor(0,1);
    lcd.print("Gas fault Detect");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,1);
  lcd.print("AirQuality888ppm   ");
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A5: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
    lcd.setCursor(0,0);
    lcd.print("Gas fault,          ");
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
    lcd.setCursor(0,0);
    lcd.print("Good air,     ");
  }
  delay(100);
}