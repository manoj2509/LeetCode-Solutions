//
// Created by Mj on 2/11/2017.
//
#include <iostream>
#include <vector>

int reversePairs(std::vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                if (nums[i] > 0 && nums[j] < 0) {
                    ans++;
                } else if ((long)nums[i] > (long)(nums[j] * 2)) {
                    ans ++;
                }
            }
            if (nums[i] == nums[j] && nums[j] < 0) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    std::vector<int> nums = {2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};
    int ans = reversePairs(nums);
    std::cout << ans;
}