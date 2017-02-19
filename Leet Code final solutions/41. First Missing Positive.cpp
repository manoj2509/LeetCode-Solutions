//
// Created by Mj on 2/3/2017.
//
#include <iostream>
#include <vector>
int firstMissingPositive(std::vector<int>& nums) {
    // Assumed that numbers are between 1 and size of nums.
    int n = nums.size();
    for (int i = 0; i < n; i++)
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1)
            return i + 1;
    return n + 1;
}

int main() {
    std::vector< int > nums = {3, 4, -1, 1};
    std::cout << "First missing positive is: " << firstMissingPositive(nums) << std::endl;
}