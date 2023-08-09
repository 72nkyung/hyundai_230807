// 22_static.cpp
#include <iostream>
using namespace std;

#if 0
int cnt = 0;
// Car의 데이터인데, 전역 변수이므로 외부에서 함부로 접근해서 변경할 수 있습니다.
//  => 정보 은닉

class Car {
public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c[5];
    cout << c[0].GetCount() << endl;
}
#endif

class Car {
private:
    static int cnt; // 정적 멤버 데이터 - 선언

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

// 소스 코드(Car.cpp)
// - 정적 멤버 데이터는 소스 파일에 외부 정의가 필요합니다.
int Car::cnt = 0; // Car의 정적 변수로 만들고 싶습니다.

int main()
{
    Car c[5];
    cout << c[0].GetCount() << endl;
}
