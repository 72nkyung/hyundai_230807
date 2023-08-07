// 1_시작2.cpp

// C++ 표준 입출력 라이브러리가 있습니다.
#include <iostream>
// std::cout -> stdout
// std::cin  -> stdin

#include <cstdio>
// printf -> stdout
// scanf  -> scanf

int main()
{
    int n = 42;
    char c = 'A';
    double d = 3.14;

    std::printf("%d, %c, %lf\n", n, c, d);

    std::cout << n << ", " << c << ", "
              << d << std::endl;
}
