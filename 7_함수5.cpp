// 7_함수5.cpp
#include <iostream>
using namespace std;

// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }

// * 함수의 인자/반환 타입만 다르고, 구현(알고리즘)이 동일할 때
//   템플릿을 이용해서 컴파일 시간에 코드를 생성할 수 있습니다.

// C++ Template
template <typename TYPE>
TYPE square(TYPE x) { return x * x; }

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
