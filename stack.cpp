// stack.cpp
#include "stack.h"

Stack::Stack()
{
    buff = new int[10];
    top = 0;
}

Stack::Stack(int size)
{
    buff = new int[size];
    top = 0;
}

Stack::~Stack()
{
    delete[] buff;
}
