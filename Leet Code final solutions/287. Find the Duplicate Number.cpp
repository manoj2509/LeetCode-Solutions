//
// Created by Mj on 1/26/2017.
//
#include <iostream>
#include <vector>
/*
 * Uses constant extra space, no modifications to the original array.
 */
int findDuplicate(std::vector<int>& nums) {
    int count;
    int n = nums.size();
    for (int num = 1; num < n; num++) {
        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] - num == 0) {
                count += 1;
            }
        }
        if (count > 1) {
            return num;
        }
    }
    return 0;
}

int main() {
    std::vector< int > nums = {1, 2, 2, 3};
    int ans = findDuplicate(nums);
    std::cout << ans << std::endl;
}