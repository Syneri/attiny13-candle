#include "RandomUtils.h"

#define RAND16_2053 ((uint16_t)(2053))
#define RAND16_13849 ((uint16_t)(13849))

uint16_t RandomUtils::_seed = 2049;

void RandomUtils::setSeed(uint16_t seed) {
  _seed = seed;
}

uint8_t RandomUtils::rand8()
{
  _seed = _seed * RAND16_2053 + RAND16_13849;
  return (uint8_t)((uint8_t)(_seed & 0xFF) + (uint8_t)(_seed >> 8));
}

uint8_t RandomUtils::rand8(uint8_t max)
{
  uint8_t r = rand8();
  return (r * max) >> 8;
}

uint8_t RandomUtils::rand8(uint8_t min, uint8_t max)
{
  uint8_t delta = max - min;
  return rand8(delta) + min;
}
