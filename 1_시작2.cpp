// 1_시작2.cpp

// C++ 표준 입출력 라이브러리가 있습니다.
#include <iostream>
// std::cout -> stdout
// std::cin  -> stdin

#include <cstdio>
// printf -> stdout
// scanf  -> stdin

#if 0
int main()
{
    int n = 42;
    char c = 'A';
    double d = 3.14;

    // std::printf("%d, %c, %lf\n", n, c, d);

    // 서식을 지정하지 않아도 변수의 타입에 따라서
    // 자동으로 처리됩니다.
    // => 연산자 오버로딩 + 함수 오버로딩
    std::cout << n << ", " << c << ", "
              << d << std::endl;
}
#endif

int main()
{
    int n;
    std::scanf("%d", &n);
    std::printf("%d\n", n);

    // 주소를 전달하지 않아도, 변수의 값을
    // 변경할 수 있습니다.
    std::cin >> n;
    std::cout << n << std::endl;
}
