// 9_레퍼런스.cpp
#include <iostream>
using namespace std;

// C++ 에서는 레퍼런스 타입이 존재합니다.
// => 기존 메모리에 새로운 이름을 부여합니다.
#if 0
int main()
{
    int n = 100;
    n = 42;
    cout << n << endl;

    int& r = n;
    r = 100;
    cout << n << endl;

    n = 42;
    cout << r << endl;
}
#endif

int main()
{
    int n = 100;

    int* p = &n;

    *p = 42;
    cout << *p << endl;
    cout << n << endl;
}
