// 9_레퍼런스3.cpp
#include <iostream>
using namespace std;

// void foo(int x[])
#if 0
void foo(int* x)
{
    cout << sizeof(x) << endl; // 8
}
#endif

void foo(int (&r)[5])
{
    cout << sizeof(r) << endl;
}

// Decay 예외
// 1) sizeof
// 2) 주소(&)
// 3) 레퍼런스

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    // x의 타입은: int[5]
    // => 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다, Decay
    cout << sizeof(x) << endl;

    // foo(x); // &x[0]
    foo(x);
}
