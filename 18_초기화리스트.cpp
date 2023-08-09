// 18_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해해야 합니다.
#if 0
int main()
{
    int a = 10; // 초기화

    int b;
    b = 10; // 대입

    // C++ 에는 반드시 초기화 해야 하는 타입이 있습니다.
    // 1) const
    // 2) reference

    const int C = 100;

    int x = 10;
    int& r = x;

    r = 10;
}
#endif

// 2. 생성자에서 멤버 데이터의 값을 초기화하기 위해서는,
//    초기화 리스트의 문법을 이용해야 합니다.
#if 0
class Sample {
    int& a;

public:
    Sample(int n)
    {
        a = n; // 초기화가 아니라 대입입니다.
    }
};
#endif

#if 0
class Sample {
    const int c;
    int& r;

public:
    // 초기화 리스트는 생성자에서만 사용할 수 있습니다.
    //  : 멤버(값) / 멤버{값}
    Sample(int a, int& rb)
        : c { a }
        , r { rb }
    {
    }
};

int main()
{
}
#endif

#if 0
class Point {
    int x;
    int y;

public:
    // 멤버 데이터는 초기화 리스트를 통해 초기화하는 것이 좋습니다.
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }
};
#endif

// 주의: 초기화 리스트의 순서대로 초기화되는 것이 아니라,
//      멤버 데이터가 선언된 순서대로 초기화됩니다.
//  => 초기화리스트를 작성하실 때, 멤버 데이터 선언 순서대로 작성하는 것이 좋습니다.
class Point {
    int x;
    int y;

public:
    Point();

    void Print() { cout << x << ", " << y << endl; }
};

// 초기화 리스트는 구현부에 작성됩니다.
Point::Point()
    // : y(10), x(y) /* 미정의 동작 - x가 먼저 초기화됩니다. */
    : x(10)
    , y(x)
{
}

int main()
{
    Point pt;
    pt.Print();
}
