// 22_static3.cpp
#include <iostream>
using namespace std;

// 1. 멤버 함수는 함수를 호출한 객체의 주소가 this로 전달됩니다.
// 2. 정적 멤버 함수는 함수를 호출한 객체의 주소가 전달되지 않습니다.
//    => this가 없습니다.

// 3. 멤버 함수 안에서 멤버 데이터를 접근하거나, 멤버 함수를 호출할 수 있습니다.
//    this->n
//    this->foo()
// 4. 멤버 함수 안에서 정적 멤버 데이터를 접근하거나 정적 멤버 함수를 호출할 수 있습니다.
//    Sample::s
//    Sample::goo()
//    => 객체(this)없이 접근이 가능합니다.

// 5. 정적 멤버 함수안에서 멤버 데이터를 접근하거나 멤버 함수를 암묵적으로 호출할 수 없습니다.
//    정적 멤버 함수는 객체의 주소(this)가 암묵적으로 전달되지 않기 때문입니다.

// 6. 정적 멤버 함수 안에서 정적 멤버 데이터와 정적 멤버 함수 호출이 가능합니다.

class Sample {
private:
    int n; // 멤버 데이터
    static int s; // 정적 멤버 데이터

public:
    Sample(int x)
        : n(x)
    {
    }

    void hoo() { }

    void foo() // 멤버 함수  void foo(Sample* this)
    {
        cout << n << endl;
        //   this->n
        hoo();
        //   this->hoo(); // Sample::hoo(this)

        cout << s << endl;
        //   Sample::s
        goo();
        //   Sample::goo();
    }

    static void goo() // 정적 멤버 함수
    {
        // cout << n << endl; // 컴파일 오류!
        //   this->n

        cout << s << endl;
        //   Sample::s
    }

    // 정적 멤버 함수에서 일반적인 멤버 데이터에 접근하거나,
    // 멤버 함수를 호출하기 위해서는, 객체의 주소를 명시적으로 전달 받으면 됩니다.

    static void goo2(Sample* self) // this의 역활을 명시적으로 전달합니다.
    {
        cout << self->n << endl;
        self->foo();
    }
};

// 정적 멤버 데이터 초기화 코드는 소스 코드에 정의해야 합니다.
int Sample::s = 100;

int main()
{
    Sample s { 42 };
    s.foo(); // Sample::foo(&s)

    s.goo(); // Sample::goo()

    s.goo2(&s);
}
