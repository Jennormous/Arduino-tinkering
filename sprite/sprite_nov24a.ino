#include <LiquidCrystal.h>

//pins 

const int l_pin = 8;
const int r_pin = 9;

//number of columns on LCD
const int lcd_width = 16; 

//LCD object

LiquidCrystal lcd(12,11,2,3,4,5);

//Define lcd character (5x7)

byte person[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010,
  B01010,
};

//chars position
int person_x = 8;

int l_prev = HIGH;
int r_prev = HIGH;

void setup() {
  // put your setup code here, to run once:

// pull-ups on buttons
pinMode(l_pin, INPUT_PULLUP);
pinMode(r_pin, INPUT_PULLUP);

//initialize and clear LCD
lcd.begin(16,2);
lcd.clear();

//register char
lcd.createChar(0, person);

}

void loop() {
  // put your main code here, to run repeatedly:
  // look for left button and move char left
  int l_state = digitalRead(l_pin);
  
  if ( (l_prev == HIGH) && (l_state == LOW) ) {
    person_x--;
    if (person_x < 0) {
      person_x = 0;
    }
  }
  // look for right button and move char right
  int r_state = digitalRead(r_pin);
  if ( (r_prev == HIGH) && (r_state == LOW) ) {
    person_x++;
    if (person_x >= lcd_width) {
      person_x = lcd_width -1;
    }
  }

//remember state

l_prev = l_state;
r_prev = r_state;

//clear screen and draw char

lcd.clear();
lcd.setCursor(person_x, 1);
lcd.write(byte(0));

delay(20);
}
