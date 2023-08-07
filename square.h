// square.h
#ifndef SQUARE_H
#define SQUARE_H

// C/C++ 동시에 사용하는 헤더를 정의할 때
// 아래와 같이 __cplusplus 매크로가 정의되어 있는지 여부에 따라 조건부 컴파일을 수행합니다.
#ifdef __cplusplus // C++ Compiler
extern "C" int square(int x);
#else
extern int square(int x);
#endif

#endif
