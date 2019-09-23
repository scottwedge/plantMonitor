#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop(){

  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      // if(Serial.available() > 16){   //need to print characters over two
      //   while(16)                    //lines accurately
      // }
      lcd.write(Serial.read());
    }
  }

}
