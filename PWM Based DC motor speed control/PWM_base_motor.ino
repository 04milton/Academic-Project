int motorA_in1 = 8;
int motorA_in2 = 9;
 int motorA_ENA = 11;
int volume_pin = A0;
int read_ADC;
int duty_cycle_lcd;
int speed;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  pinMode(motorA_in1,OUTPUT);
  pinMode(motorA_in2,OUTPUT);
  pinMode(motorA_ENA,OUTPUT);
  pinMode(volume_pin, INPUT);

  lcd.backlight();
  lcd.init();
  lcd.begin(16,2);  
  lcd.setCursor(0,0);
  lcd.print(" WELCOME To Our ");
  lcd.setCursor(0,1);
  lcd.print("    Project");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Group 1: ");
  lcd.setCursor(0,1);
  lcd.print("221101 - 221118");
  delay(2000);
  lcd.clear();

}

void loop() {
  // right forward
  read_ADC = analogRead(volume_pin);
  speed = map(read_ADC, 0, 1023, 25, 255);
  duty_cycle_lcd = map(read_ADC, 0, 1023, 0, 100); 
  
  digitalWrite(motorA_in1, HIGH);
  digitalWrite(motorA_in2, LOW);
  analogWrite(motorA_ENA,speed);
  lcd.setCursor(0,0);
  lcd.print("   Duty Cycle ");
   
  lcd.setCursor(7,1);
  lcd.print(duty_cycle_lcd);
  lcd.print("%  ");
  delay(300);

}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
