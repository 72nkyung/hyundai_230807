// 5_const.cpp
#include <iostream>
using namespace std;

// 1. C의 const와 C++의 const는 차이가 있습니다.

// 2. 상수
//  - 컴파일 타임 상수
//     "상수의 초기값이 컴파일 시간에 결정된다면, 컴파일 상수가 됩니다."
//   : 메모리를 사용하지 않습니다.
//     컴파일 시간에 컴파일 타임 상수에 대한 모든 접근은
//     상수값으로 기록됩니다.

//  - 런타임 상수
//    "상수의 초기값이 컴파일 시간에 결정될 수 없다면, 런타임 상수가 됩니다."
//    : 실행 시간에 값을 변경할 수 없지만,
//      값을 읽기 위해서는 메모리로부터 실행 시간에 값을 로드합니다.

// C++11 - constexpr
//   : 상수 표현식에 지정할 수 있는 키워드입니다.

#if 0
int main()
{
    int a = 10 + 5;
    // 10 + 5 의 연산은, 컴파일 타임에 수행할 수 있으므로,
    // 컴파일 시간에 연산을 수행해서, 기계어에는 15로 기록되어 있습니다.

    // constexpr const int C1 = 100;
    constexpr int C1 = 100;

    // 위의 상수는 컴파일 타임 상수로써,
    // 상수 표현식입니다.

    // int arr[N];
    // C언어에서는 허용하지 않습니다.
    // 배열의 크기는 컴파일 타임에 결정되어야 합니다.
    // => 배열의 크기는 상수 표현식만 허용됩니다.

    // constexpr const int C2 = a; // 컴파일 오류! 상수 표현식 아닙니다.
    const int C2 = a;

    // 실행 시간에 변하는 값(변수)를 통해 상수를 만들 경우,
    // 컴파일 타임에 상수의 값을 결정할 수 없습니다.
    // => 런타임 상수
}
#endif

#if 0
// GCC, Clang
// => VLA(가변 길이 배열), 표준이 아닙니다.
int main()
{
    int n = 42;
    // int arr[n];
    // - 배열의 크기는 상수 표현식, 컴파일 타임 결정되어야 합니다.
}
#endif

int main()
{
    constexpr int c1 = 100;

    int n = 100;
    const int c2 = n;

    // 실행 시간에 이후에 값을 변경할 수 없습니다.
    // C++에서는 반드시 const 변수는 초기화를 해야 합니다.
}
