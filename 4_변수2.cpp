// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 42;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2(42);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

#if 0
// C++11, Uniform Initialization(일관된 초기화)
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = { 42 };

    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2 { 42 };

    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };
}
#endif

// - C/C++은 실수 타입이 정수 타입으로의
//   더 큰 표현 범위를 가지는 정수가 더 작은 표현 범위를 가지는 정수 타입의
//   암묵적인 변환을 허용하고 있습니다.
//  => 컴파일 에러와 경고가 발생하지 않습니다.
#if 0
int main()
{
    double d = 3.14;
    int x = d;
    // 1. 소수점이 사라집니다.
    // 2. int 표현범위를 넘어선 데이터가 대입될 경우,
    //    오버플로우가 발생할 수 있습니다.

    long long n = 10000LL;
    int x2 = n;
    // - 오버플로우의 위험성이 있습니다.
}
#endif

#if 1
// Uniform Initialization을 사용하는 경우,
// 암묵적인 변환(실수 -> 정수, 정수 -> 실수, long -> int)을
// 허용하지 않습니다.
// => Preventing Narrow
//   : Overflow가 발생하는지 여부를 확인할 수 있도록
//     암묵적인 변환을 허용하지 않습니다.

//  : 명시적인 캐스팅이 필요합니다.
#include <climits>

int main()
{
    double d = 3.14;
    // int x = { d }; // 에러!

    if (d > INT_MAX || d < INT_MIN) {
        std::cout << "Overflow" << std::endl;
    } else {
        int x = { (int)d }; // Uniform Copy initialization
    }

    long long n = 10000LL;
    // int x2 { n }; // 에러!

    if (n > INT_MAX || n < INT_MIN) {
        std::cout << "Overflow" << std::endl;
    } else {
        int x2 { (int)n }; // Uniform Direct initialization
    }
}
#endif
