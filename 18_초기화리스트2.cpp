// 18_초기화리스트2.cpp
#include <iostream>
using namespace std;

// * 초기화 리스트를 반드시 작성해야 하는 경우
// 1) const 멤버 데이터
// 2) reference 멤버 데이터

// 3) 클래스의 멤버 데이터 클래스가 기본 생성자를 제공하지 않는 경우,
//    명시적으로 생성자에서 초기화리스트를 통해 멤버 데이터를 초기화해야 합니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }
};

class Rect {
    Point leftTop;
    Point rightBottom;

public:
    // 컴파일러가 생성하는 기본생성자의 형태
    // Rect()
    // : leftTop(), rightBottom()
    // { }

    Rect()
        : leftTop { 10, 20 }
        , rightBottom { 30, 40 }
    {
    }
};

int main()
{
    Rect rect;
}
