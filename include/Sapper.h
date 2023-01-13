#pragma once
#include <array>
#include <random>
class Sapper
{
private:
    std::array<std::array<int32_t, 10>, 10> m_fill_field;     // сгенерированное поле
    std::array<std::array<int32_t, 10>, 10> m_logic_field;    // игровая логика поля

public:
    Sapper();
    void print();
};