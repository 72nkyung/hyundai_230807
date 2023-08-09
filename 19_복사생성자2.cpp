// 19_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

// 복사 생성자가 호출되는 경우
// 1) 객체가 함수로 call by value로 전달될 때
//   : C++에서는 객체를 인자로 전달할 때, 값을 복사해서 전달하지 않고,
//     const& 형태로 전달합니다.

// 해결방법: void foo(const Sample& s)
#if 0
void foo(Sample s) // Sample(const Sample&)
{
} // ~Sample()

int main()
{
    Sample s; // Sample()

    cout << "------------" << endl;
    foo(s);
    cout << "------------" << endl;
}
#endif

#if 0
class Point {
public:
    int x;
    int y;

    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print() { cout << x << ", " << y << endl; }
};

void foo(const Point& pt) // pt를 읽기만 하겠습니다.
{
    // pt.x = 100;
    // pt.y = 200;
}

int main()
{
    Point pt { 10, 20 };
    foo(pt);
    pt.Print();
}
#endif
