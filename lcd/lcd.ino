//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>
#include <GyverButton.h>

#if defined(__AVR_ATmega2560__)
#pragma message "Скачай MegaCore: github.com/AlexTutorial/MegaCore"
#endif

GButton button(2);

int32_t tmr = millis();
int seconds = 0;
bool enSec = false;
byte j1 = 11;
byte fallSand1 = j1;
bool line1ends = false;
String border =  "---------XX---------";
int line1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  button.setType(LOW_PULL);
  Serial.begin(9600);
}



void loop()
{
  if(seconds%90 == 0 && seconds!=0) setO();
  if (!enSec) draw(border);
  else if (seconds < 10)  draw("---------" + String(seconds) + "----------");
  else if (seconds < 100) draw("---------" + String(seconds) + "---------");
  else draw("---------" + String(seconds) + "--------");

  button.tick();
  if (button.isHold()||seconds>999) asm volatile("jmp 0x0000"); //If is hold - restart program
  if (button.isClick()) enSec = !enSec; //is click code

}
