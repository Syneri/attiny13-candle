// LED Candle imitation optimized for ATtiny13.
//
// Скетч использует 392 байт (38%) памяти устройства. Всего доступно 1024 байт.
// Глобальные переменные используют 64 байт (100%) динамической памяти, оставляя 0 байт для локальных переменных. Максимум: 64 байт.
// 
// ATtiny13 pinout:
//
// RESET °. . 5V
//   PB3  . . 
//        . . PWM 1
//   GND  . . PWM 0
//

#include "RandomUtils.h"

// Arduino Nano
// #define PWM_LED_PIN 3
// ATtiny13
#define PWM_LED_PIN 0

#define Y_MAX 255
#define Y_MIN 100
#define CANDLE_LIGHT_DELAY 70

// Значения яркости светодиода от 0 до 255.
byte ledBrightnessValues[62] = {
  197, 215, 230, 242, 248, 250, 247, 239, 227, 212, 
  196, 180, 166, 153, 144, 138, 136, 137, 141, 148, 
  155, 163, 170, 175, 179, 180, 178, 175, 171, 166, 
  162, 159, 158, 159, 164, 171, 180, 192, 204, 215, 
  225, 233, 237, 237, 232, 222, 209, 193, 175, 156, 
  138, 122, 110, 102, 100, 102, 110, 122, 138, 156, 
  175, 193 //, 210, 223
};

void setup() {
  // Serial.begin(9600);
}

void loop() {
  // generateSequence();
  candleLight();
}

void candleLight() {
  // Длительность плавного изменения яркости.
  int stillLength = RandomUtils::rand8(10, 30);
  // Индекс с которого не будет лишнего колебания "фитиля".  
  int stillStartIndex = RandomUtils::rand8(sizeof(ledBrightnessValues) - stillLength);
  // Индекс до которого не будет лишнего колебания "фитиля".
  int stillEndIndex = stillStartIndex + stillLength;

  for (int i = 0; i < sizeof(ledBrightnessValues); i++) {
    // Serial.println(ledBrightnessValues[i]);
    int analogValue = ledBrightnessValues[i];
    if (i < stillStartIndex || i > stillEndIndex) {
      int flickerAdder = RandomUtils::rand8(10, 35);
      analogValue -= flickerAdder;
    }
    if (analogValue > Y_MAX) {
      analogValue = Y_MAX;
    }
    analogWrite(PWM_LED_PIN, analogValue);
    delay(CANDLE_LIGHT_DELAY);
  }
}

void generateSequence() {
  float x = 0.0;
  float increase = 0.1;
  for (int i = 0; i < sizeof(ledBrightnessValues); i++) {
    x += increase;
    float kVal = (Y_MAX - Y_MIN) * 0.25; // 16
    float incValue = Y_MAX - (Y_MAX - Y_MIN) * 0.5; // 223
    int result = kVal * (sinf(2 * x) + sinf(PI * x)) + incValue;
    Serial.print(result);
    Serial.print(", ");
    if ((i + 1) != 0 && (i + 1) % 10 == 0) {
      Serial.println();
    }
    delay(CANDLE_LIGHT_DELAY);
  }
  Serial.println();
  Serial.println("end");
}
