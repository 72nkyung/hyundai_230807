// 4_변수4.cpp
#include <iostream>
using namespace std;

// 변수와 동일한 타입의 변수를 만들고 싶다면
//  - decltype 연산자를 사용하면 됩니다.
//  - C++11

// decltype은 초기화가 반드시 필요하지 않습니다.

int main()
{
    int n = 10;
    decltype(n) x; // x의 타입은 n과 동일한 int 타입이 됩니다.

    const int c = 42;
    decltype(c) x2 = 100; // x2의 타입은 c와 동일한 const int 타입입니다.
    // x2 = 100; // 컴파일 오류
}
