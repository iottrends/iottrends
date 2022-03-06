#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()

{
	lcd.begin(16,2);
ldc.init();

	lcd.backlight();
	lcd.clear();
	lcd.setCursor(4,0);
	lcd.print("Hello World");

}
void loop()
{

}
