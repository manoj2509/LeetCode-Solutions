//
// Created by Mj on 1/26/2017.
//
#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int ans = 0;
    // Bit manipulation - XOR of a number by itself is 0, that is in any order.
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

int main () {
    std::vector< int > nums = {1, 1, 2, 2, 3};
    int ans = singleNumber(nums);
    std::cout << ans << std::endl;
}