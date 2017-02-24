//
// Created by Mj on 1/27/2017.
//
#include <iostream>
#include <string>
#include <sstream>

std::string toString(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}
std::string countAndSay(int n) {
    std::string inp = "1";
    if (n == 1) {
        return inp;
    }
    std::string outp;
    char count;
    for (int i = 0; i < n - 1; i++) {
        int len = inp.length();
        int j = 0;
        outp = "";
        while (j < len) {
            char temp = inp[j];
            count = '0';
            while (temp == inp[j] && j < len) {
                j++;
                count++;
            }
            outp = outp + toString(count) + temp;
        }
        inp = outp;
    }
    return outp;
}

int main() {
    std::string ans = countAndSay(4);
    std::cout << ans << std::endl;
    std::cout << (char)('0' + 1) << std::endl;
}