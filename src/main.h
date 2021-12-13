#include <Arduino.h>

#define MERAH 13
#define KUNING 12
#define HIJAU 11
#define MULTITASKING_STATUS 10

float getCelcius();
float getFahren();
float getReamur();
float getKelvin();
String checkAlarm();
void cetakSuhu();
void setAlarm(uint8_t pin, uint16_t durasi);