// 15_생성자2.cpp
#include <iostream>
#include <cstdlib> // malloc, free
using namespace std;

class Point {
public:
    Point() { cout << "Point()" << endl; }
    Point(int a, int b) { cout << "Point(int, int)" << endl; }

    ~Point() { cout << "~Point()" << endl; }
};

// 전역 객체
// => 프로그램 시작 전(main 이전)에 생성자가 호출되고
//    프로그램이 종료 되기 직전에 소멸자가 호출됩니다.

// 지역 객체
// => 함수가 시작될 때, 객체가 생성되고
//    함수가 종료할 때 객체가 소멸됩니다.

// * malloc을 이용해서 객체를 생성하면, 생성자가 호출되지 않습니다.
// * free를 통해서 객체를 파괴하면, 소멸자가 호출되지 않습니다.
// * new를 통해서 객체를 생성하면, 생성자가 호출됩니다.
// * delete를 통해서 객체를 파괴하면, 소멸자가 호출됩니다.
int main()
{
    // Point* pt = new Point; // Point()
    // Point* pt = new Point(10, 20); // Point(int, int)
    Point* pt = new Point { 10, 20 }; // Point(int, int)

    delete pt;
}

#if 0
int main()
{
    Point* pt = static_cast<Point*>(malloc(sizeof(Point)));
    free(pt);
}
#endif

#if 0
Point pt;

int main()
{
    cout << "main begin" << endl;
    // Point pt;

    cout << "main end" << endl;
}
#endif
