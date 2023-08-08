// 7_함수7.cpp
#include <iostream>
using namespace std;

// 기존
#if 0
int add(int a, int b)
{
    return a + b;
}

int (*foo())[3]
{
    static int x[3] = { 10, 20, 30 }; // int[3]
    return &x; // int (*)[3]
}
#endif

#if 1
// 함수를 만드는 새로운 방법을 제공합니다. - C++11
// - Trailing Return Type
auto add(int a, int b) -> int { return a + b; }

auto foo() -> int (*)[3]
{
    static int x[3] = { 10, 20, 30 }; // int[3]
    return &x; // int (*)[3]
}

// 1) 반환 타입을 명시하지 않는 경우, 컴파일러가 추론합니다.
//  => 반환 타입을 생략할 수 있습니다.
auto goo()
{
    static int x[3] = { 10, 20, 30 }; // int[3]
    return &x; // int (*)[3]
}

// int + long => long + long => long
// long + int => long + long => long
// double + float => double + double => double

// 2) 인자의 타입을 통해 반환 타입을 결정할 경우,
//    아래와 같이 작성되어야 합니다.
template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
}
#endif

// Kotlin, Swift, Go, Rust ...
// => Trailing Return Type으로 함수를 정의합니다.
