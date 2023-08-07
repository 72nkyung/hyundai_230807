// 4_변수5.cpp
#include <iostream>
using namespace std;

// typedef
// => Type Aliasing
#if 0
typedef int N; // N == int
typedef int ARR3[3]; // ARR3 == int[3]

int Add(int a, int b) { return a + b; }

typedef int (*FP)(int a, int b); // FP == int(*)(int, int)

int main()
{
    FP f;
    f = &Add;
    cout << f(10, 20) << endl;

    int a = 10;
    N b = 20;
    b = a;

    int x[3];
    ARR3 x2;

    x2[0] = 10;
    x2[1] = 20;
}
#endif

// using
// 1. namespace
//    - using 선언
//      using std::cout;
//    - using 지시어
//      using namespace std;

// 2. C++11, Type aliasing
//   => typedef를 대체하는 목적으로 도입되었습니다.

// typedef int N;
using N = int;

// typedef int ARR3[3];
using ARR3 = int[3];

// typedef int (*FP)(int, int);
//  식별자 = 타입
using FP = int (*)(int, int);

int Add(int a, int b) { return a + b; }

int main()
{
    FP fp = &Add;
    cout << (*fp)(10, 20) << endl;

    N a = 10;
    cout << a << endl;

    ARR3 x;
    x[0] = 10;
    cout << x[0] << endl;
}
