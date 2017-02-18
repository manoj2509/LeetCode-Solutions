//
// Created by Mj on 1/27/2017.
//
#include <iostream>
#include <string>
#include <sstream>

std::string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    std::string num = "1";
    std::string temp, ret, count;
    std::string tempAns = "";
    for (int i = 0; i < n; i++) {
        temp = num;
        tempAns = "";

    }
    for (int i = 0; i < n - 1; i++) {
        mul = 1;
        temp= num;
        tempAns = 0;
        while (temp != 0) {
            count = 0;
            ret = temp % 10;
            temp = temp/10;
            count ++;
            while (temp % 10 == ret) {
                temp /= 10;
                count ++;
            }
            tempAns += ret * mul;
            mul *= 10;
            tempAns += count * mul;
            mul *= 10;
        }
        num = tempAns;
//        std::cout << tempAns << std::endl;
    }
    std::stringstream ss;
    ss << tempAns;
    return ss.str();
}

int main() {
    std::string ans = countAndSay(9);
    std::cout << ans << std::endl;
}