//
// Created by Mj on 2/2/2017.
//

#include <vector>
#include <iostream>

std::vector<int> plusOne(std::vector<int>& digits) {
    int carry = 1;
    int sumTemp = 0;
    std::vector<int> ans = digits;
    int i = digits.size() - 1;
    while (carry == 1 && i >= 0) {
        ans[i] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
        i--;
    }
    if (carry == 1 && i == -1) {
        ans.insert(ans.begin(), carry);
    }
    return ans;
}

int main() {
    std::vector< int > digits = {9, 9};
    std::vector< int > ans = plusOne(digits);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i];
    }
}