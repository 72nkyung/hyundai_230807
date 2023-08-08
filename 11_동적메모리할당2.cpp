// 11_동적메모리할당2.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    int* p1 = static_cast<int*>(malloc(sizeof(int)));
    // p1가 가르키는 메모리 영역은 초기화가 되어 있지 않습니다.
    free(p1);

    int* p2 = new int;
    // p2가 가르키는 메모리 영역도 초기화가 되어 있지 않습니다.
    delete p2;

    // Direct initialization
    // : new를 통해서 할당된 메모리는 초기화가 가능합니다.
    int* p3 = new int(100);
    cout << *p3 << endl;
    delete p3;

    int* p4 = new int { 200 };
    cout << *p4 << endl;
    delete p4;

    int* p5 = new int[3] { 10, 20, 30 };
    cout << p5[0] << endl;
    cout << p5[1] << endl;
    cout << p5[2] << endl;
    delete[] p5;

    Point* pt = new Point { 10, 20 };
    cout << pt->x << endl;
    cout << pt->y << endl;
    delete pt;
}
