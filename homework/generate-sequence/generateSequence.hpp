#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> vec;
    int val = step;

    if (count > 0) {
        for (size_t i = 0; i < count; i++) {
            vec.push_back(val);
            val += step;
        }
    }
    return vec;
}
