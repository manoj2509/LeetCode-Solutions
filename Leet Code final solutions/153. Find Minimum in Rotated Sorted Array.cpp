//
// Created by Mj on 1/30/2017.
//
#include <iostream>
#include <vector>

/*
 * Binary Search Implementation.
 *
 * int findMin(std::vector<int>& nums) {
    int beg = 0;
    int end = nums.size() - 1;
    int mid = (beg + end) / 2;
    while (beg != mid) {
        std::cout << beg << "~" << mid << "~" << end << std::endl;
        if (nums[mid] <= nums[end]) {
            end = mid;
        } else {
            beg = mid;
        }
        mid = (beg + end) / 2;
    }
    if (nums[beg] > nums[end]) {
        return nums[end];
    }
    std::cout << nums[beg] << "--" << nums[end] << std::endl;
    return nums[beg];
}
 */

int findMin(std::vector<int>& nums) {
    int i;
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return nums[0];
    }
    i = n - 1;
    while (i >= 1 && nums[i - 1] < nums[i]) {
        i--;
    }
    std::cout << i << std::endl;
    return nums[i];
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << findMin(nums) << std::endl;
}