#include <stdint.h>
#ifndef RandomUtils_h
#define RandomUtils_h

class RandomUtils {
  private:
    static uint16_t _seed;
  public:
    static void setSeed(uint16_t seed);
    static uint8_t rand8();
    static uint8_t rand8(uint8_t max);
    static uint8_t rand8(uint8_t min, uint8_t max);
};

#endif
