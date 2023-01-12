#pragma once
#include <array>
#include <random>
class Sapper
{
private:
    std::array<std::array<int32_t, 10>, 10> m_fill_field;     // игровое поле

public:
    Sapper();
};