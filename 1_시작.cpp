// 1_시작.cpp

// Compile: Ctrl + F7
// Compile + Linking + Run: Ctrl + F5

// 1. 확장자
// - C언어: .c
// -  C++: .cpp .cc .cxx ...

// 2. 컴파일러
// - Microsoft Visual C/C++ Compiler: MSVC
// - GNU C/C++ Compiler: GCC
// - LLVM Compiler: Clang

// 3. C++ 표준
// - C++98: 1차 표준안
//   C++03: 1차 표준안 개정
// - C++11: 2차 표준안      => Modern C++
//   C++14: 2차 표준안 개정
// - C++17: 3차 표준안
//   C++20

// 4. C++안에서 C의 문법을 지원합니다.
// > C의 표준과 C++안에서의 C의 표준은 다릅니다.

#if 0
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);

	printf("Hello, C\n");
	return 0;
}
#endif

// C++의 표준헤더는 확장자가 없는 경우가 많습니다.
#include <cstdio>
// => C의 표준라이브러리 함수를 std의 이름 공간에서 사용할 수 있습니다.

int main()
{
    std::printf("Hello, C++\n");

    // return 0;
    // 프로세스가 정상 종료되었음을 의미합니다.
    // : C++에서 자동적으로 컴파일할 때, 컴파일러가 동일한 기계어를
    //   만들어줍니다.
}
