//
// Created by Mj on 1/30/2017.
//

#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    if (nums.size() < 1) {
        return -1;
    }
    int i = 0;
    int n = nums.size();
    while(i < n) {
        if (nums[i] < target) {
            i++;
        } else {
            break;
        }
    }
    if ((i < n) && (nums[i] == target)) {
        return i;
    }
    std::cout << "B" << std::endl;
    i = n - 1;
    while (i >= 0) {
        if (nums[i] > target) {
            i--;
        } else {
            break;
        }
    }
    if ((i >= 0) && (nums[i] == target)) {
        return i;
    }
    return -1;
}
int main() {
    std::vector< int > nums = {1};
    int ans = search(nums, 0);
    std::cout << ans;
}