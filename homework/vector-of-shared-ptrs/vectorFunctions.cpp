#include <iostream>
#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> vec;

    for (size_t i=0; i<count; i++)
    {
        std::shared_ptr<int> ptr = std::make_shared<int>(i);
        vec.push_back(ptr);
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>> vec)
{
    for (auto ptr : vec)
    {
        if (ptr.get() != nullptr)
        {
            std::cout << *ptr << std::endl;
        }
    }
}

void add10(std::vector<std::shared_ptr<int>> vec)
{
    for (auto ptr : vec)
    {
        if (ptr.get() != nullptr)
        {
            *ptr += 10;
        }
    }
}

void sub10(int * const ptr)
{
    if (ptr != nullptr)
    {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>> vec)
{
    for (auto ptr : vec)
    {
        sub10(ptr.get());
    }
}