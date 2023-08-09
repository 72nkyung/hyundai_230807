// 10_캐스팅.cpp
#include <iostream>
#include <cstdlib> // malloc, free
using namespace std;

// - 명시적인 캐스팅이 필요한 경우가 있습니다.
// - C의 캐스팅은 목적을 파악하기 위해서는 코드를 분석해야 합니다.
// => C++은 용도와 목적에 따라서 4가지의 캐스팅 연산자를 제공하고 있습니다.
#if 0
int main()
{
    // - 실수 타입을 정수 타입으로의 변환
    double d = 3.14;
    int n { (int)d };

    // - 더 큰 표현 범위를 가지는 정수 타입을
    // 더 작은 표현 범위의 정수로의 변환
    long long l = 1000LL;
    int x { (int)l };

    // - void*를 구체적인 포인터타입으로의 변환
    int* p = (int*)malloc(sizeof(int));
    // C 에서는 void*를 구체적인 포인터타임으로의 암묵적인 변환을 허용하지만,
    // C++ 에서는 허용하지 않습니다.

    // - 메모리를 재해석
    int n2 = 0x12345678;
    char* pc = (char*)&n2;
    printf("%x %x %x %x\n", pc[0], pc[1], pc[2], pc[3]);

    // - const를 제거하는 목적
    int x2 = 100;
    const int* pcn = &x2;

    int* pn = (int*)pcn;
}
#endif

#if 1
// C++ 캐스팅 연산자
// 1) static_cast
//  : 가장 기본적인 C++의 캐스팅 연산자
// "연관성 있는 타입간의 안전한 캐스팅에서 사용합니다."
//   실수 -> 정수
//   더 큰 정수 타입 -> 작은 정수 타입
//   void* -> 구체적인 포인터

// 2) reinterpret_cast
//  : 메모리 재해석 용도로 사용합니다.
//  => 잘못 사용할 경우, 미정의 동작의 위험성이 있습니다.

// 3) const_cast
//  : 메모리의 상수성(const)를 제거해서, 타입 불일치 문제를 해결하는 목적으로
//    사용합니다.

// 4) dynamic_cast
//  => 이후에 살펴봅니다.

int main()
{
    // - 실수 타입을 정수 타입으로의 변환
    double d = 3.14;
    // int n { (int)d };
    int n { static_cast<int>(d) };

    // - 더 큰 표현 범위를 가지는 정수 타입을
    // 더 작은 표현 범위의 정수로의 변환
    long long l = 1000LL;
    // int x { (int)l };
    int x { static_cast<int>(l) };

    // - void*를 구체적인 포인터타입으로의 변환
    // int* p = (int*)malloc(sizeof(int));
    int* p = static_cast<int*>(malloc(sizeof(int)));

    // - 메모리를 재해석
    int n2 = 0x12345678;
    // char* pc = (char*)&n2;
    // char* pc = static_cast<char*>(&n2); /* 오류! */
    char* pc = reinterpret_cast<char*>(&n2);
    printf("%x %x %x %x\n", pc[0], pc[1], pc[2], pc[3]);
    long* pl = reinterpret_cast<long*>(&n2);
    *pl = 1000L; // 할당되지 않은 메모리에 대한 접근 => 미정의 동작

    // - const를 제거하는 목적
    int x2 = 100;
    const int* pcn = &x2;

    // int* pn = (int*)pcn;
    // int* pn = static_cast<int*>(pcn); /* 오류 */
    // int* pn = reinterpret_cast<int*>(pcn); /* 오류 */
    int* pn = const_cast<int*>(pcn);
}
#endif
