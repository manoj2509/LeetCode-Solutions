//
// Created by Mj on 2/3/2017.
//
#include <iostream>
#include <unordered_map>

std::string addBinary(std::string a, std::string b) {
    std::unordered_map< int, std::string > sum = {{0, "0"}, {1, "1"}, {2, "0"}, {3, "1"}};
    std::unordered_map< int, int > carry = {{0, 0}, {1, 0}, {2, 1}, {3, 1}};
    std::string ans;
    int aSize = a.length() - 1;
    int bSize = b.length() - 1;
    int car = 0;
    while (aSize >= 0 || bSize >= 0) {
        int oneNum = (aSize >= 0) ? (a[aSize] - 48) : 0;
        int twoNum = (bSize >= 0) ? (b[bSize] - 48) : 0;
        ans = sum[oneNum + twoNum + car] + ans;
        car = carry[oneNum + twoNum + car];
        aSize--;
        bSize--;
    }
    if (car == 1) {
        ans = sum[car] + ans;
    }
    return ans;
}

int main() {
    std::cout << addBinary("11", "1") << std::endl;
}