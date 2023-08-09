// 17_this.cpp
#include <iostream>
using namespace std;

// * 멤버 함수는 호출할 때, 첫번째 인자로 객체의 주소가 전달됩니다.
//   전달된 객체의 주소는 멤버 함수 안에서 this를 통해서 접근할 수 있습니다.

class Point {
    int x;
    int y;

public:
    void Set(int a, int b) // void Set(Point* this, int a, int b)
    {
        cout << this << endl;

        x = a; // this->x = a;
        y = b; // this->y = b;
    }
};

void Set(int a, int b)
{
}

int main()
{
    Set(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    void Set(int,int)
    */

    Point pt1, pt2;

    cout << &pt1 << endl;
    pt1.Set(10, 20); // Point::Set(&pt1, 10, 20)
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR pt1$[rsp]  ; rcx = &pt1
        call    void Point::Set(int,int)
    */

    cout << &pt2 << endl;
    pt2.Set(100, 200); // Point::Set(&pt2, 100, 200)
    /*
        mov     r8d, 200
        mov     edx, 100
        lea     rcx, QWORD PTR pt2$[rsp] ; rcx = &pt2
        call    void Point::Set(int,int)
    */
}
