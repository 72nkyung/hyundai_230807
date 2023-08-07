// 4_변수.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입
// 1. struct
// 2. union
// 3. enum

#if 0
//     tag
struct complex {
    int re;
    int im;
};

union data {
    int i32;
    long long i64;
};

enum task_state {
    RUNNING,
    STOPPED
};

// C에서는 사용자 정의 타입 변수를 만들 때, 반드시
// struct 태그 / union 태그 / enum 태그 형태로 타입을 명시해야 합니다.
int main()
{
    struct complex c1;
    union data data;
    enum task_state state;
}
#endif

struct Complex {
    int re;
    int im;
};

union Data {
    int i32;
    long long i64;
};

enum TaskState {
    RUNNING,
    STOPPED
};

// C++에서는 태그가 아니라, 타입입니다.
// > struct / union / enum은 더 이상 명시하지 않습니다.
int main()
{
    Complex c1;
    Data data;
    TaskState state;
}
