#pragma once

int NWD(int lhs, int rhs) {
    int result = 0;
    lhs = std::abs(lhs);
    rhs = std::abs(rhs);

    if (lhs == 0 || rhs == 0) {
        result = (rhs > lhs) ? rhs : lhs;
    } else {
        while (lhs != rhs) {
            if (lhs > rhs) {
                lhs -= rhs;
            } else {
                rhs -= lhs;
            }
        }
        result = lhs;
    }
    return result;
}

int NWW(int lhs, int rhs) {
    if (lhs == 0 || rhs == 0) {
        return 0;
    } else {
        return std::abs(lhs * rhs / NWD(lhs, rhs));
    }
}
