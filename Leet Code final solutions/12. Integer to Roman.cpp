//
// Created by Mj on 12/21/2016.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int num = 2822;
    num = 110;
    // divide the number into parts. thousands, hundreds, tens and ones
    // generate codes accordingly
    string ans;
    // Maps all the strings.
    std::unordered_map <int, std::string> roman = {{1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"},
                                            {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
                                            {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"},
                                            {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"},
                                            {90, "XC"}, {100, "C"}, {200, "CC"}, {300, "CCC"},
                                            {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"},
                                            {800, "DCCC"}, {900, "CM"}, {1000, "M"}, {2000, "MM"},
                                            {3000, "MMM"}};
    std::vector <int> numParts;
    int temp = num;
    int divisor = 10;
    while (temp > 0) {
        int x = temp % divisor;
        numParts.push_back(x);
        std::cout << temp << "--" << divisor << "--" << x << endl;
        divisor *= 10;
        std::unordered_map <int, std::string>::iterator iter;
        if (x == 0) {
            // all the zero ending numbers.
            continue;
        } else {
            temp = temp - x;
            iter = roman.find(x);
            if (iter == roman.end()) {
                exit(1);
            }
            ans = iter->second + ans;
        }
        std::cout << ans << std::endl;
    }
}