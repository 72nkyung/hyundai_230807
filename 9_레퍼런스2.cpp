// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void inc1(int x)
{
    ++x;
}

void inc2(int* px)
{
    ++(*px);
}

void inc3(int& r)
{
    ++r;
}

int main()
{
    int x = 10;
    // inc1(x); // Call by value
    // inc2(&x); // Call by pointer(주소를 전달합니다.)
    inc3(x); // Call by reference(기존 메모리에 새로운 이름을 부여합니다.)

    cout << x << endl;
}
