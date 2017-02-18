//
// Created by Mj on 1/29/2017.
//

#include <iostream>
int guess(int version) {
    if (version > 10) {
        return 1;
    } else if (version < 10) {
        return -1;
    } else {
        return 0;
    }
}
int guessNumber(int n) {
    int beg = 1;
    int end = n;
    int mid = (beg + end) / 2;
    while (end != beg) {
        if (guess(mid) == -1) {
            end = mid;
        } else if (guess(mid) == 1) {
            beg = mid + 1;
        } else {
            return mid;
        }
        mid = (beg + end) / 2;
    }
    return mid;
}
int main() {
    int ans = guessNumber(10);
    std::cout << ans << std::endl;
}