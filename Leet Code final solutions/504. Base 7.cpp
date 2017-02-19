//
// Created by Mj on 2/11/2017.
//
#include <iostream>

std::string convertTo7(int num) {
    int n = num;
    std::string ans;
    if (num == 0) {
        return "0";
    }
    bool flag = false;
    if (n < 0) {
        flag = true;
        n = n* (-1);

    }
    int temp;
    while (n > 0) {
        temp = n % 7;
        ans = to_string(temp) + ans;
        n /= 7;
    }
    if (flag) {
        ans  = "-" + ans;
    }
    return ans;
}