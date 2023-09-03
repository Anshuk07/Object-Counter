//Object counter
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
//Variables
int x = 0;
int input = A0;
int state = 1;

LiquidCrystal_I2C lcd(0x27, 16, 2);
//In git
void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {  
  //Print on LCD
  lcd.setCursor(4, 0);
  lcd.print("Counted:");
  lcd.setCursor(2, 1);
  lcd.print(x);
  lcd.print(" Objects");
  
  int counter = digitalRead(A0);//Input from IR sensor

  if (state == 0) { 
    switch (counter) {

      case 1:
        state = 1;
        //lcd.setCursor(2, 1);
        x = x + 1;
        //lcd.print(x);
        break;
      case 0: state = 0; break;
    }
  }

  if (counter == 0) {
    state = 0;
  }
  }
