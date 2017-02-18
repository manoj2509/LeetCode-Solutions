//
// Created by Mj on 1/30/2017.
//

#include <vector>
#include <iostream>

int findMin(std::vector<int>& nums) {
    int beg = 0;
    int end = nums.size() - 1;
    int mid = (beg + end) / 2;
    while (beg != mid) {
        std::cout << beg << "~" << mid << "~" << end << std::endl;
        if (nums[mid] < nums[end]) {
            end = mid;
        } else if (nums[mid] > nums[end]){
            beg = mid;
        } else {            // Did this because we cannot predict where should we move to find the minimum.
            end--;          // Eg: (1, 3, 3), (3, 3, 1, 3), (3, 1, 3, 3), so we lessen the end from array portion.
        }
        mid = (beg + end) / 2;
    }
    if (nums[beg] > nums[end]) {
        return nums[end];
    }
    std::cout << nums[beg] << "--" << nums[end] << std::endl;
    return nums[beg];
}

int main() {
//    std::vector< int > nums = {4, 5, 6, 7, 0, 1, 2};
    std::vector< int > nums = {3, 3, 1, 3};
    std::cout << findMin(nums) << std::endl;
}