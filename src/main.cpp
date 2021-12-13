#include <main.h>

void setup()
{
  Serial.begin(9600);

  while (lcd.begin(16, 2) != 1)
  {
    Serial.println(F("PCF8574 is not connected or lcd pins declaration is wrong. Only pins numbers: 4,5,6,16,11,12,13,14 are legal."));
    delay(5000);
  }

  lcd.print(F("PCF8574 is OK..."));
  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print(F("Hello world!"));

  lcd.setCursor(0, 2);
  lcd.print(F("Random number:"));
}


void loop()
{
  /* print dynamic text */
  lcd.setCursor(14, 2);
  lcd.print(random(10, 1000));
  lcd.write(LCD_SPACE_SYMBOL);

  delay(1000);
}
