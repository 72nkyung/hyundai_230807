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
