// 19_복사생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 수행하지 않는 기본 생성자를 제공합니다.
// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

// 3. 사용자가 자신과 동일한 타입의 객체를 인자로 받는 생성자(복사 생성자)를 제공하지 않으면
//    컴파일러는 자동으로 멤버 데이터를 복사하는 복사 생성자를 제공합니다.

class Point {
    int x;
    int y;

public:
    // 컴파일러가 제공하는 복사 생성자
    Point(const Point& rhs)
        : x { rhs.x }
        , y { rhs.y }
    {
        cout << "Point(const Point&)" << endl;
    }

    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() { cout << x << ", " << y << endl; }
};

int main()
{
    Point pt1 { 10, 20 };
    pt1.Print();

    // * 복사 생성자가 호출되는 객체 생성 방법
    // Point pt2 = pt1;
    // Point pt2 = { pt1 };
    // Point pt2(pt1);
    Point pt2 { pt1 };

    pt2.Print();
}
