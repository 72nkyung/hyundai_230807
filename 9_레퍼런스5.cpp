// 9_레퍼런스5.cpp
#include <iostream>
using namespace std;

// 레퍼런스
// 1. lvalue reference
//  : lvalue만 참조할 수 있는 레퍼런스

// 2. const lvalue reference
//  : const lvalue 참조할 수 있고,
//    lvalue, rvalue를 참조할 수 있습니다.

// 3. rvalue reference

class Color {
public:
    Color(int r, int g, int b) { cout << "Color(int, int, int)" << endl; }
    ~Color() { cout << "~Color()" << endl; }
};

// lvalue / rvalue를 인자로 참조할 수 있는 함수입니다.
void SetBackgournd(const Color& color)
{
}

int main()
{
    Color color(100, 50, 100);
    SetBackgournd(color);

    SetBackgournd(Color(100, 50, 100));

    cout << "---------" << endl;
    const Color& r2 = Color(100, 50, 100); // 임시 객체, rvalue
    cout << "---------" << endl;

    // 임시 객체는 레퍼런스의 참조가 있을 때, 수명이 연장됩니다.
}
