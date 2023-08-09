// 20_객체복사6.cpp
#include <iostream>
#include <string>
using namespace std;

class Sample {
public:
    Sample() { }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }
    Sample(Sample&& rhs) { cout << "Sample(Sample&&)" << endl; }
};

// std::move - lvalue를 rvalue로 변경할 수 있습니다.
int main()
{
    Sample s1;

    Sample s2 = s1; // 복사 생성자
    Sample s3 = std::move(s1); // 이동 생성자
}
