//
// Created by Mj on 1/25/2017.
//
#include <iostream>
#include <vector>

std::string longestPalindrome(std::string s) {
    std::string ans;
    int n = s.length();
    int len[n][n];

    if (s.length() < 2) {
        return s;
    }
    // Write recursive logic here.
    std::cout << ans << len[0][n - 1] << std::endl;
    return ans;
}

int main() {
    std::string ans = longestPalindrome("abcda");
}