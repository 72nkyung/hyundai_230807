// 7_함수5.cpp
#include <iostream>
using namespace std;

// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }

// * 함수의 인자/반환 타입만 다르고, 구현(알고리즘)이 동일할 때
//   템플릿을 이용해서 컴파일 시간에 코드를 생성할 수 있습니다.

// C++ Template
#if 0
template <typename TYPE>
inline TYPE square(TYPE x) { return x * x; }
// 장점: 적은 코드로 모든 타입에서 동작하는 일반적인 함수를 정의할 수 있습니다.
// 단점
//  - 인자의 타입의 종류에 따라서 함수가 생성되므로,
//    인자의 타입의 종류가 많을 수록 코드 메모리의 사용량이 증가될 수 있다.
//  => 인라인 최적화

//  - 템플릿은 반드시 헤더를 통해서 제공되어야 합니다.

int main()
{
    cout << square(100) << endl; // TYPE -> int
    cout << square(10000LL) << endl; // TYPE -> long long
    cout << square(3.14) << endl; // TYPE -> double
    // 컴파일러가 함수 호출 인자의 타입을 통해 코드를 자동으로 생성합니다.
    //  => 암묵적 타입 지정

    // cout << square(5.5f) << endl; // TYPE -> float

    cout << square<double>(5.5f) << endl;
    // TYPE -> double
    //  => 명시적 타입 지정
}
#endif

template <typename T1, typename T2>
void foo(T1 a, T2 b)
{
}

int main()
{
    foo(10, 3.14);
    // T1 -> int
    // T2 -> double
    // foo<int, double>(10, 3.14)
    //    ------------- --------
    //         |           |
    //      타입 파라미터   값 파라미터
}
