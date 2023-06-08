// Компиляция cygwin: g++ -o Test test.cpp RandomUtils.h RandomUtils.cpp
// Запуск: ./Test

#include <iostream>
#include "RandomUtils.h"

int main() {
  RandomUtils::setSeed(2023);
  std::cout << "rand8: " << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << unsigned(RandomUtils::rand8(10, 30)) << " ";
  }
  std::cout << std::endl; 
  return 0;
}
