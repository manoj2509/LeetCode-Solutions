//
// Created by Mj on 1/6/2017.
//
#include <iostream>

std::string reverseString(std::string s) {
    std::string ans = "";
    if (s.length() == 0) {
        return s;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        ans += s[i];
    }
    return ans;
}

int main () {
    std::string s = "hello";
    std::string ans = reverseString(s);

    std::cout << "Ans: " << ans;
}