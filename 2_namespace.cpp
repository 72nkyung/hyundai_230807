// 2_namespace.cpp
#include <iostream>

// namespace
// 1. C에서는 동일한 이름의 함수 또는 변수를 여러개 만들 수
//    없습니다.
//  > 다른 이름을 약속합니다.
// 2. C++은 이름 충돌의 문제를 해결하기 위해서,
//    문법을 도입하였습니다.
//  > namespace
#if 0
// a.cpp
void audio_foo() { }
int audio_n = 0;

// b.cpp
void video_foo() { }
int video_n = 10;
#endif

// a.cpp
namespace audio {
void foo() { }
int n = 0;
}

// b.cpp
namespace video {
void foo() { }
int n = 10;

namespace mp3 {
    void play() { }
}

namespace mp4 {
    void play() { }
}

}

// 3. namespace를 사용하면 프로그램의 각 요소를
//    관련된 요소끼리 그룹화할 수 있습니다.

// 4. C++ 표준의 모든 요소는 std 이름 공간안에 약속되어 있습니다.
//   std::cout / std::cin / std::printf / std::scanf

int main()
{
    video::mp3::play();
    video::mp4::play();

    audio::foo();
    video::foo();

    std::cout << audio::n << std::endl;
    std::cout << video::n << std::endl;
}
