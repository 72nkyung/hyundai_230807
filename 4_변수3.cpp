// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int* p = x;
    // p의 타입은 x의 타입에 의존성이 있습니다.

    int e = x[0];
}
#endif

// auto - C++11
// 1. 컴파일 타임에 변수의 타입을 우항의 타입을 기반으로 결정합니다.
// 2. 의존성 있는 타입에 대해서 사용을 할 때,
//    타입이 변경되더라도, 코드를 수정할 필요가 없습니다.
// 3. C의 auto의 키워드를 다른 의미로 사용합니다.
#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    auto p = x;
    auto e = x[0];

    // auto n;
    // - auto를 사용하기 위해서는 반드시 초기화(우항)가 필요합니다.
}
#endif

#if 1
// auto는 우항과 타입과 동일한 타입으로 추론되는 것이 아닙니다.
// => Type deduction

int main()
{
    const int n = 42; // 상수 - const int

    auto x = n; // auto -> int
    x = 10;

    const auto x2 = n; // const int
    // x2 = 10; // 컴파일 오류!
}
#endif
