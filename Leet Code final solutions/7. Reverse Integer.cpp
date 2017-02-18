//
// Created by Mj on 11/18/2016.
//

#include <iostream>
#include <limits.h>
#include <assert.h>

int main() {
    int x = 1534236469;
    // Code to copy.
    int reverseX = 0;
    int negFlag = 0;
    int temp;
    int orig = x;
    if (x < 0) {
        negFlag = 1;
        x *= (-1);
    }
    while (x) {
        temp = x%10;
        reverseX = reverseX*10 + temp;
        std::cout << reverseX << std::endl;
        x = x/10;
    }
    if (negFlag == 1) {
        reverseX *= (-1);
    }
    if (orig > 1000000000) {
        reverseX = 0;
    }
    std::cout << reverseX;
}