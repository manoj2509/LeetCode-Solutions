//
// Created by Mj on 1/29/2017.
//

#include <iostream>

int guess(int version) {
    if (version > 8) {
        return 1;
    } else if (version < 8) {
        return -1;
    } else {
        return 0;
    }
}

int getMoneyAmount(int n) {
    int ans = 0;
    int beg = 1;
    int end = n;
    int mid;
    while (end != beg) {
        mid = (beg + end) / 2;
        ans += mid;
        std::cout << "~~" << mid << std::endl;
        beg = mid + 1;
    }
    return ans;
}

int main() {
    int ans = getMoneyAmount(10);
    std::cout << ans << std::endl;
}