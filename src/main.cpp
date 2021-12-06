#include <main.h>

uint8_t jalan[4][3] = {
  {11, 12, 13}, //timur
  {8, 9, 10}, //barat
  {5, 6, 7}, //selatan
  {2, 3, 4} //utara
};

uint8_t durasiHatiHati = 1;
uint8_t durasiJalan = 5;

void setup()
{
  Serial.begin(9600);
  for (auto &&arah : jalan){for (auto &&lampu : arah){pinMode(lampu, OUTPUT);}}
}

void loop()
{
  for(uint8_t arah = 0; arah < 4; arah++)
  {
    go(arah);
  }
}

void go(uint8_t arah)
{
  for(uint8_t index = 0; index < 4; index++)
  {
      digitalWrite(jalan[index][MERAH], HIGH);
      digitalWrite(jalan[index][KUNING], LOW);
      digitalWrite(jalan[index][HIJAU], LOW);
  }

  digitalWrite(jalan[arah][MERAH], LOW);
  digitalWrite(jalan[arah][KUNING], HIGH);

  uint16_t millisDulu = millis();
  while(true)
  {
    uint16_t durasi = millis() - millisDulu;
    if(durasi == (durasiHatiHati) * (uint16_t)1000)
    {
      digitalWrite(jalan[arah][KUNING], LOW);
      digitalWrite(jalan[arah][HIJAU], HIGH);
    }
    else if(durasi == (durasiHatiHati+durasiJalan) * (uint16_t)1000)
    {
      digitalWrite(jalan[arah][HIJAU], LOW);
      digitalWrite(jalan[arah][KUNING], HIGH);
    }
    else if(durasi == (durasiHatiHati+durasiJalan+durasiHatiHati) * (uint16_t)1000)
    {
      break;
    }
  }
}