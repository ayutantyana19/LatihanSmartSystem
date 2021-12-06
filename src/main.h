#include <Arduino.h>

#define MERAH 0
#define KUNING 1
#define HIJAU 2

const char* ARAH[] = {"TIMUR", "BARAT", "SELATAN", "UTARA"};
const char* LAMPU[] = {"MERAH", "KUNING", "HIJAU"};

void go(uint8_t arah);

