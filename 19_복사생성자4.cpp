// 19_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

// 절대 지역 객체를 참조로 반환하면 안됩니다.
// 함수가 종료한 이후에 사라지는 메모리에 대한 참조이므로, 미정의 동작입니다.
// Sample& foo()

// 1) RVO(Return Value Optimization): 반환값 최적화
// - 지역 객체를 값으로 반환할 때, 임시 객체를 반환하면 반환용 임시 객체 생성의 복사 생성 비용을 제거합니다.
#if 0
Sample foo()
{
    return Sample();
}
#endif

// 2) NRVO(Named Return Value Optimization)
// - 지역 객체를 값으로 반환할 때, 일반적인 지역 객체도 반환용 임시 객체 생성의 복사 생성 비용을 제거할 수 있습니다.
Sample foo()
{
    Sample s;
    return s;
}

// 핵심: 지역 객체를 값으로 반환할 때, 반환용 임시 객체의 복사 생성 비용은,
//      컴파일러의 최적화(RVO / NRVO)에 의해서 사라집니다.

int main()
{
    cout << "----------" << endl;
    foo();
    cout << "----------" << endl;
}
