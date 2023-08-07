// 7_함수2.cpp
#include <iostream>
using namespace std;

// C는 동일한 이름의 함수를 여러개 만들 수 없습니다.
#if 0
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squared(3.14) << endl;
}
#endif

// C++은 동일한 이름의 함수를 여러개 만들 수 있습니다.
//  => 함수의 이름은 동일하지만, 인자 정보(인자의 타입과 개수)가 다른 경우에만 허용합니다.
//  => "함수 오버로딩(Overloading, 중복 적재)"
//    : 네임 맹글링

int square(int x) { return x * x; }
// 0000000100003d30 T __Z6squarei

double square(double x) { return x * x; }
// 0000000100003d40 T __Z6squared

long long square(long long x) { return x * x; }
// 0000000100003d60 T __Z6squarex

// C++ 컴파일러는 함수의 이름에 인자 정보가 포함되는 형태로 컴파일 됩니다.

// C에서 만든 함수를 C++에서 호출하거나,
// C++로 구현된 함수를 C에서 호출하는 것이 불가능합니다.
//  해결방법
//    : extern "C"를 통해 함수를 선언합니다.
//   > C의 형태로 함수를 만들기 때문에,
//     함수 오버로딩이 불가능합니다.

// C로 구현된 foo를 C++에서 호출할 때의 선언입니다.
extern "C" void foo();

// C++로 구현된 함수를 C에서 호출할 수 있습니다.
extern "C" void goo();
void goo()
{
    cout << "goo" << endl;
}
// 0000000000000050 T _goo

int main()
{
    foo();

    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(100000000LL) << endl;
}
