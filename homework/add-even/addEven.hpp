#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int sum = 0;

    for (int n : numbers)
    {
        if (0 == n % 2)
        {
            sum += n;
        }
    }
    return sum;
}
