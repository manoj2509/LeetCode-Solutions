//
// Created by Mj on 1/29/2017.
//

#include <vector>
#include <iostream>

int searchInsert(std::vector<int>& nums, int target) {
    int i;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    if (i == nums.size()) {
        return i;
    }
}
int main() {
    std::vector< int > nums = {1, 3, 5, 6};
    int target = 2;
    int ans = searchInsert(nums, target);
    std::cout << searchInsert(nums, target) << std::endl;
}