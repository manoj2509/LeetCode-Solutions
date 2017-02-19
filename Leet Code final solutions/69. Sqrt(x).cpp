//
// Created by Mj on 2/17/2017.
//
#include <iostream>
#include <math.h>
/*
 * Can be done using binary search too. Just find the point where it is the root between 0 and x.
 */
int mySqrt(int x) {
    float inp = x;
    if (inp == 0) {
        return 0;
    }
    float prev = 2;
    float next = 0;
    do {
        if (next != 0) {
            prev = next;
        }
        next = ((prev + (inp / prev)) / 2);
        std::cout << next << "=" << prev << "~~" << floor(inp / prev) << std::endl;
    } while ((floor(next)) != floor(prev));
    if ((int)next * (int)next > x) {
        return (int)next - 1;
    }
    return (int)(next);
}

int main() {
    std::cout << mySqrt(2147395599) << std::endl;
}