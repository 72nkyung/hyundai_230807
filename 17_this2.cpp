// 17_this2.cpp
#include <iostream>
using namespace std;

#if 0
class Sample {
public:
    Sample() { }
    ~Sample() { }
};

int main()
{
    Sample s;
    // Sample::Sample()
} // Sample::~Sample()
#endif

// private 소멸자
//  의도: 객체 생성을 new를 통해서만 허용하겠다.
//  => 객체를 파괴하는 기능을 멤버 함수를 통해서 제공해야 합니다.

#if 0
class Sample {
private:
    ~Sample() { cout << "~Sample()" << endl; }

public:
    Sample() { cout << "Sample()" << endl; }

    void Destroy() // void Destroy(Sample* this)
    {
        delete this;
    }
};

// Sample s; // - 전역 객체도 생성 불가능

int main()
{
    // Sample s; - 지역 객체 생성 불가능

    Sample* p = new Sample;

    p->Destroy(); // Sample::Destroy(p)
    // 이순간 소멸자가 수행되어야 합니다.

    // delete p;
}
#endif

class Sample {
private:
    int ref;

    ~Sample() { cout << "~Sample()" << endl; }

public:
    Sample()
        : ref(1)
    {
        cout << "Sample()" << endl;
    }

    void AddRef() { ++ref; }
    void Destroy() // void Destroy(Sample* this)
    {
        if (--ref == 0) {
            delete this;
        }
    }
};

int main()
{
    Sample* s1 = new Sample(); // ref: 1

    Sample* s2 = s1;
    s2->AddRef(); // ref: 2

    s1->Destroy();
    s2->Destroy();
}
