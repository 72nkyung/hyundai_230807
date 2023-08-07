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

int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(100000000LL) << endl;
}
