// 9_레퍼런스4.cpp
#include <iostream>
using namespace std;

// 레퍼런스
// 1. & - lvalue reference
// => lvalue 참조 가능합니다.

// lvalue(좌변값), rvalue(우변값)
// - lvalue: 좌변, 우변에 모두 사용 가능합니다.
// - rvalue: 우변에서만 사용이 가능합니다.

#if 0
void foo(int& r)
{
    cout << r << endl;
}

// a = 3;
int main()
{
    int a = 10;

    foo(a); /* OK, a는 lvalue 입니다. */
    // foo(3); /* NO, 3은 rvalue 입니다. */

    // int& r1 = a; /* OK, a는 lvalue 입니다. */
    // int& r2 = 3; /* NO, 3은 rvalue 입니다. */
}
#endif

// 2. const lvalue reference
//  : lvalue와 rvalue를 모두 참조할 수 있습니다.
#if 0
void foo(const int& r)
{
}

int main()
{
    int a = 10;

    const int& r1 = a; /* OK! const lvalue reference */
    const int& r2 = 10; /* OK! const lvalue reference */

    foo(a);
    foo(10);
}
#endif

// 3. rvalue의 경우 좀 더 효과적으로 코드를 작성할 수 있는 경우가 있습니다.
//    C++11, rvalue reference 새롭게 도입되었습니다.
//   => rvalue 만 참조 가능합니다.
void foo(int& r)
{
    cout << "lvalue" << endl;
}

void foo(int&& r)
{
    cout << "rvalue" << endl;
}

int main()
{
    int a = 10;

    // int&& r1 = a; /* NO!, lvalue 입니다. */
    int&& r2 = 10; /* OK!, rvalue 입니다. */

    foo(a);
    foo(10);
}
