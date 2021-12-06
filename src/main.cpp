#include <main.h>

void setup()
{
  for (auto &&arah : jalan){for (auto &&lampu : arah){pinMode(lampu, OUTPUT);}}
}

void loop()
{
  for(uint8_t arah = 0; arah < 4; arah++){go(arah);}
}