//
// Created by Mj on 1/29/2017.
//
#include <iostream>
bool isBadVersion(int version) {
    return version >= 1;
}
// Learn handling of large integers.
int firstBadVersion(int n) {
    int beg = 1;
    int end = n;
    int mid = (beg + end) / 2;
    while (end != beg) {
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            beg = mid + 1;
            std::cout << mid << std::endl;
        }
        mid = (beg + end) / 2;
    }
    return mid;
}

int main() {
    int ans = firstBadVersion(1);
    std::cout << ans << std::endl;
}