// 15_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 수행하지 않는 인자 없는 생성자를 만들어줍니다.
#if 0
class Point {
    int x;
    int y;
    // public:
    //     Point() {}  <- 컴파일러가 자동으로 생성해줍니다.
};

int main()
{
    Point pt; // Point() => 기본 생성자(Default Constructor)
}
#endif

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.
#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    // Point pt(10, 20);
    Point pt { 10, 20 };

    // Point pt2; /* 컴파일 오류! */
}
#endif

// 3. 생성자는 오버로딩이 가능합니다.
//    생성자의 인자 정보에 따라서 여러 개의 생성자를 제공할 수 있습니다.
//    => 객체를 생성하는 다양한 방법을 제공할 수 있습니다.
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    Point()
    {
        x = 0;
        y = 0;
    }
};

int main()
{
    // Point pt(10, 20);
    Point pt { 10, 20 }; // Point(int, int)

    Point pt2; // Point()
}
