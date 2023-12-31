// 7_함수4.cpp
#include <iostream>
using namespace std;

#if 0
int square(int x)
{
    return x * x;
}

// C 에서는 함수 호출의 오버헤드를 제거하기 위해서,
// 매크로 함수를 사용하는 경우가 있습니다.
#define SQUARE(x) ((x) * (x))
// - 매크로 함수의 문제점
//  : 우선순위에 문제가 발생할 수 있습니다.
//    - 치환되는 인자 영역을 괄호로 감싸주어야 합니다.

#define DBL(x) ((x) + (x))
//  : 매크로 함수에 의해서 치환되는 모든 영역이 괄호로 감싸주어야 합니다.

//   * 매크로 함수에 ++, -- 인자를 전달할 때
//     해당 인자가 하나의 표현식에서 두번이상 치환되는 경우
//     미정의 동작이 발생합니다.
//   => 매크로 함수의 인자에 대해서 ++, -- 연산은 절대 사용하면 안됩니다.

int main()
{
    int x = 10;

    cout << square(x + x) << endl;
    cout << square(++x) << endl;

    cout << SQUARE(x + x) << endl;
    //      x + x * x + x
    //     (x + x) * (x + x)

    // cout << SQUARE(++x) << endl;
    //   (++x) * (++x)
    //   : C/C++ 에서 하나의 연산식에서 동일한 변수를 참조하는데,
    //     변수의 값이 변하는 연산(부수효과)이 존재하는 경우,
    //     결과를 알 수 없습니다. => 미정의 동작

    ++x;
    cout << SQUARE(x) << endl;

    int result = DBL(x) * DBL(x + x);
    // (x) + (x) * (x) + (x)
    // ((x) + (x)) * ((x) + (x))
}
#endif

// 인라인 함수
//  => 함수를 호출하지 않고, 기계어로 치환합니다.
//  => 함수 호출 오버헤드를 제거하는 문법
//  1) 컴파일 최적화 명령입니다.
//     /Ob1
//  2) 인라인 최적화가 수행되면, 함수의 구현의 기계어코드는 코드 메모리에서
//     사라집니다.
//  3) 함수의 길이가 짧은 경우, 인라인 최적화가 수행될 수 있지만,
//     함수의 길이가 긴 경우, 인라인 함수라고 하더라도 인라인 최적화가 수행되지 않을 수 있습니다.
//  4) C99 표준에도 인라인 함수가 도입되었습니다.
//     static inline void foo() {}

//  5) 인라인 함수는 컴파일 시간에 함수의 호출이 아닌 기계어로 치환을 수행하기 때문에
//     함수의 구현을 헤더를 통해서 제공해야 합니다.
//    => 인라인 함수는 Internal linkage를 갖습니다.

inline int square(int x)
{
    return x * x;
}

#define SQUARE(x) ((x) * (x))

int main()
{
    int x = 10;
    printf("%d\n", square(++x));
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
    */

    printf("%d\n", SQUARE(x));
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
    */
}
