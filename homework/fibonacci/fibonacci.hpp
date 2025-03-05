#pragma once
#include <vector>

int fibonacci_iterative(int sequence) {
    int result = 0;
    std::vector<int> fibo = {0, 1};

    if (sequence <= 1) {
        result = fibo[sequence];
    } else {
        for (size_t i = 2; i <= sequence; i++) {
            fibo.push_back(fibo[i - 1] + fibo[i - 2]);
        }
        result = fibo.back();
    }

    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0) {
        return 0;
    } else if (sequence == 1) {
        return 1;
    } else {
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }
}
