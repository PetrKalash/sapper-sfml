#include "Sapper.h"

Sapper::Sapper()
{
    // Заполняем каждую ячейку на игровом поле случайными числами
    for (size_t x{}; x < 10; ++x)
        for (size_t y{}; y < 10; ++y)
            m_fill_field.at(x).at(y) = std::mt19937(std::random_device {}())() % 9;
}