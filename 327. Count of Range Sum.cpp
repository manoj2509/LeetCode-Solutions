//
// Created by Mj on 2/9/2017.
//
#include <iostream>
#include <vector>

int countRangeSum(std::vector<int>& nums, int lower, int upper) {
    // We have to find all the sums of all the ranges
    // then give out the total number of ranges that are in between the given limits.

}

int main() {
    std::vector< int > nums = {-2, 5, -1};
    int ans = countRangeSum(nums, -2, 2);
    std::cout << ans << std::endl;
}