//
// Created by Mj on 1/26/2017.
//
#include <iostream>
#include <vector>
/*
 * Idea is to XOR all the numbers, so that we are left with A ^ B.
 * Then we take the lowest different bit.
 * And separate the numbers based on that bit. So those 2 numbers will be separated.
 * Now XOR those 2 divided portions again and get those unique numbers.
 */
std::vector< int > singleNumber(std::vector< int >& nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        ans ^= nums[i];
    }
    int lowestOneBit = ans & (~(ans - 1));
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] & lowestOneBit) {
            x ^= nums[i];
        } else {
            y ^= nums[i];
        }
    }
    return {x, y};
}

int main() {
    std::vector< int > nums = {1, 2, 1, 3, 2, 5};
    std::vector< int > ans = singleNumber(nums);
    std::cout << ans[0] << std::endl;
}