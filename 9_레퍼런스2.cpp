// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

void inc1(int x)
{
    ++x;
}

// 포인터가 사용되기 전에는 반드시 유효성 체크를 해야합니다.
void inc2(int* px)
{
    if (px) {
        ++(*px);
    }
}

// 레퍼런스를 통해 포인터를 대체할 수 있다면,
// 레퍼런스를 사용하는 것이 더 좋을 때 많습니다.
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
