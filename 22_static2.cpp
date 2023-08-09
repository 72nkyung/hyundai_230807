// 22_static2.cpp
#include <iostream>
using namespace std;

// 1. 정적 멤버 데이터는 전역 변수와 동일한 영역에 생성되는 변수입니다.
//    객체의 크기에 포함되지 않습니다.
// 2. 정적 멤버 데이터는 모든 객체가 공유합니다.

// 3. 멤버 함수는 객체를 생성해서, 객체를 통해서만 사용이 가능합니다.
// 4. 객체를 생성하지 않아도, 호출 가능한 멤버 함수가 있습니다.
//   => 정적 멤버 함수

class Car {
private:
    int color; // 객체의 상태
    static int cnt; // 클래스의 상태
public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    static int GetCount() { return cnt; } // 정적 멤버 함수
    // 일반 함수와 동일하지만, 클래스의 접근 제어를 사용할 수 있습니다.
};

int Car::cnt = 0;

int main()
{
    cout << sizeof(Car) << endl;

    // 정적 멤버 함수를 호출하는 방법 2가지
    // 1. 클래스
    cout << Car::GetCount() << endl;

    // 2. 객체
    Car car;
    cout << car.GetCount() << endl;
}
