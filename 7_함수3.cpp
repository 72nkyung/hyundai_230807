// 7_함수3.cpp
#include <iostream>
using namespace std;

// * 함수 오버로딩 주의사항
//  - int foo() { }
//  - void foo() { }
// 1. 함수의 인자 정보가 동일하고, 반환 타입만 다른 경우
// 오버로딩은 허용되지 않습니다.

// 2. 기본 파라미터의 문법과 같이 사용하는 경우,
//    모호성 오류가 발생할 가능성이 있습니다.
void foo(int n = 100) { cout << "foo(int): " << n << endl; }
void foo() { cout << "foo(void)" << endl; }

int main()
{
    foo(100); // OK!

    // foo();
    // - 컴파일러는 기본 파라미터의 함수인지,
    //   진짜 인자가 없는 함수인지 구분할 수 없습니다.
    //  => 컴파일 오류!
}
