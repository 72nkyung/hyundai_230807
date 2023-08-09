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

#if 0
void foo(int (&r)[5])
{
    cout << sizeof(r) << endl;
}
#endif

// Decay 예외
// 1) sizeof
// 2) 주소(&)
// 3) 레퍼런스

#if 0
int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    // x의 타입은: int[5]
    // => 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다, Decay
    cout << sizeof(x) << endl;

    // foo(x); // &x[0]
    foo(x);
}
#endif

#if 0
// Decay: 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
// 예외
// 1) sizeof
// 2) &(주소)
// 3) &(레퍼런스)
int main()
{
    int x[3] = { 10, 20, 30 };
    // x: int[3]
    cout << sizeof(int[3]) << endl; // 12
    cout << sizeof(x) << endl; // 12

    cout << sizeof(&x[0]) << endl; // 8

    int* p = x; // &x[0]

    int(*p2)[3];
    p2 = &x; // x: int[3], &x: int(*)[3]

    int(&r)[3] = x;
    cout << sizeof(r) << endl;
}
#endif

// C 에서 배열을 이용하는 함수를 구현하는 방법
#if 0
void PrintArray(int* x, int n)
{
    for (int i = 0; i < n; i++) {
        cout << x[i] << endl;
    }
}

int main()
{
    int x1[3] = { 10, 20, 30 };
    int x2[5] = { 1, 2, 3, 4, 5 };

    PrintArray(x1, 3);
    PrintArray(x2, 5);
}
#endif

#if 0
void PrintArray(int (&x)[3])
{
    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (size_t i = 0; i < len; ++i) {
        cout << x[i] << endl;
    }
}

void PrintArray(int (&x)[5])
{
    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (size_t i = 0; i < len; ++i) {
        cout << x[i] << endl;
    }
}
#endif

template <typename TYPE>
void PrintArray(TYPE& x)
{
#if 0
    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (size_t i = 0; i < len; ++i) {
        cout << x[i] << endl;
    }
#endif

    for (auto e : x) {
        cout << e << endl;
    }
}

int main()
{
    int x1[3] = { 10, 20, 30 };
    PrintArray(x1);

    int x2[5] = { 1, 2, 3, 4, 5 };
    PrintArray(x2);
}
