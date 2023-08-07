// square.cpp
#include <iostream>
#include "square.h"

// extern "C" int square(int x);
// 함수를 C의 형태로 만들어야 합니다.

int square(int x)
{
    std::cout << "square(int)" << std::endl;
    return x * x;
}
