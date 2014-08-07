/*
@author Justin Grammens ( justin@localtone.com )
You are free to use and modify this source code as you wish.
This sketch is used to select the name of a winner for drawings at the http://arduino.mn user group.
It has been tested to work with the SainSmart LCD Keypad and Arduino UNO R2 and greater.
*/

#include <LiquidCrystal.h>
#include <LCDKeypad.h>

#define numUsers (sizeof(names)/sizeof(char *))

LCDKeypad lcd;

char* names[] = { "NAME1", "NAME2", "ETC" };

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Good luck");
  lcd.setCursor(0,1);
  lcd.print("Arduino.MN!");
  waitButton();
  waitReleaseButton();
}

void pickName() {
  lcd.clear();
  int namesSize = sizeof(names) / sizeof(int);
  long randNumber = random(namesSize);
  lcd.print(names[randNumber]);
  
}

void loop() {
  lcd.clear();
  pickName();
  waitButton();
  waitReleaseButton();
}


int waitButton()
{
  int buttonPressed; 
  waitReleaseButton;
  lcd.blink();
  while((buttonPressed=lcd.button())==KEYPAD_NONE)
  {
  }
  delay(50);  
  lcd.noBlink();
  return buttonPressed;
}

void waitReleaseButton()
{
  delay(50);
  while(lcd.button()!=KEYPAD_NONE)
  {
  }
  delay(50);
}


