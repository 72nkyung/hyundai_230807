// 19_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

// 2. 함수에서 객체를 값으로 반환할 때
//  해결방법: 지역 객체는 값으로 반환해야 합니다.
//          함수가 종료되어도 유효한 객체는 참조로 반환하는 것이 더 좋습니다.

Sample s;

// Sample foo()
Sample& foo()
{
    return s;
    // 1) 함수에서 객체를 값으로 반환하면, 반환용 임시 객체가 복사 생성자를 통해 생성됩니다.
    //    Sample(const Sample&)
}

int main()
{
    cout << "----------" << endl;
    foo();
    // 2) 반환용 임시 객체가 파괴됩니다.
    //  ~Sample()

    cout << "----------" << endl;
}
