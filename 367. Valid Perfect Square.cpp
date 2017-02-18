//
// Created by Mj on 2/17/2017.
//
#include <iostream>

bool isPerfectSquare(int num) {
    if (num == 1) {
        return true;
    }
    int high = std::min(46341, num);
    int low = 0;
    int mid;
    do {
        mid = (low + high) / 2;
        std::cout << low << " ~~ " << high << std::endl;
        int mult = mid * mid;
        if (mult > num) {
            high = mid;
        } else if (mult < num) {
            low = mid;
        } else {
            return true;
        }

    } while ((low + 1) != high);
    return false;
}

int main() {
    std::cout << isPerfectSquare(2147395600);
}