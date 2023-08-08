// test.c

#include <stdio.h>

// C 에서는 함수의 인자가 없는 경우, 반드시 void를 명시해야 합니다.
void foo(void) { }
void goo() { }

int main(void)
{
    // foo(10, 20);
    goo(10, 20);

    return 0;
}
