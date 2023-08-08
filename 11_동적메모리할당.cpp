// 11_동적메모리할당.cpp
#include <iostream>
#include <cstdlib> // malloc, free
using namespace std;

// 1. malloc, free는 함수입니다.
//  void* malloc(size_t size);
//  void free(void* ptr);

// 2. malloc은 메모리의 크기를 인자로 받고, 할당된 메모리의 주소를
//    void*로 반환합니다.
//  => 구체적인 포인터 타입으로의 명시적인 변환이 필요합니다.

// 3. free는 할당받은 메모리의 주소를 전달 받습니다.
//    NULL이 전달될 경우, 아무일도 수행하지 않습니다.

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));

    *p = 100;
    cout << *p << endl;

    free(p);

    int* ptr = NULL;
    // ..

    free(ptr);
}
#endif

// 4. C++은 동적 메모리 할당의 기능을 연산자로 제공합니다.
//    new / delete

// 5. new는 타입을 전달합니다.
//    new 연산자의 결과는 전달받은 타입의 주소 타입이 결과입니다.
//    => 명시적인 캐스팅이 필요하지 않습니다.

// 6. delete 연산자를 통해 할당받은 메모리를 해지할 수 있습니다.
//    NULL이 전달되었을 때, 아무일도 수행하지 않습니다.

int main()
{
    int* p = new int;

    *p = 100;
    cout << *p << endl;

    delete p;

    int* p2 = NULL;
    delete p2;
}
