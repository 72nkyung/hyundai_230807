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

// 포인터와 레퍼런스의 차이점을 이해해야 합니다.
// - 포인터 변수: 다른 변수의 주소를 저장하고, 주소를 통해 값을 읽거나 변경할 수 있습니다.
// - 레퍼런스  : 기존 변수의 새로운 이름을 부여합니다.
//            레퍼런스를 통해 기존 변수의 메모리에 값을 읽거나 변경할 수 있습니다.
#if 0
int main()
{
    int n = 100;

    int* p = &n;

    *p = 42;
    cout << *p << endl;
    cout << n << endl;
}
#endif

int main()
{
    int n = 100;
    int* p = NULL;
    // 포인터는 아무것도 참조하고 있지 않을 때,
    // 널 초기화가 가능합니다.

    // int& r;
    // - 반드시 초기화가 필요합니다.
    // - 널 초기화도 불가능합니다.

    int& r = n;
}
