#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_SPACE_SYMBOL 0x20
LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);