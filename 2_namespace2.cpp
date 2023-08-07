// 2_namespace2.cpp
#include <iostream>

// * namespace를 사용하는 방법 3가지

// 방법 1. 전체 이름을 명시하는 방법
#if 0
namespace audio {
namespace mp3 {
    void play() { }
}
}

int main()
{
    audio::mp3::play();

    std::cout << "Hello, C++" << std::endl;
}
#endif

#if 0
namespace audio {
namespace mp3 {
    void play() { }
}
}

// 방법 2. using 선언(declaration)
using audio::mp3::play;
using std::cout;
using std::endl;

int main()
{
    play();

    cout << "Hello, C++" << endl;
}
#endif

namespace audio {
namespace mp3 {
    void play() { }
}
}

#if 0
// 방법 3. using 지시어(Directive)
// > 특정한 이름 공간(namespace)에 있는 모든 것을
// 암묵적으로 접근할 수 있습니다.
using namespace std;
using namespace audio::mp3;
using namespace audio;

int main()
{
    // using namespace audio;
    mp3::play();

    // using namespace audio::mp3;
    play();

    cout << "Hello, C++" << endl;
}
#endif

#if 0
// * using 지시어는 이름 충돌의 문제가 발생할 수 있습니다.
// - 일반적으로 현업에서 잘 사용하지 않습니다.

// using std::cout;
// using std::endl;
using namespace std;

int count = 100;

int main()
{
    // cout << count << endl;
    // C++의 표준 라이브러리 안에 std::count 함수가 있습니다.
}

// * using 선언 / using 지시어는 헤더 파일에서는 절대 사용하면 안됩니다.
#endif

// 전역 공간의 전역 변수
int count = 42;

namespace audio {

int count = 10;

void play()
{
    // std::cout << "audio::play - " << audio::count << std::endl;

    // std::cout << "audio::play - " << count << std::endl;
    // 같은 이름 공간안에 존재하는 함수 또는 변수에 암묵적으로 접근이
    // 가능합니다.

    std::cout << "audio::play - " << ::count << std::endl;
    //                              ----
    //                           전역 이름 공간
}
}

int main()
{
    audio::play();
}
