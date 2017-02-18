//
// Created by Mj on 2/1/2017.
//
#include <iostream>
#include <vector>
#include <unordered_map>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map< int, int > test;
    for (int i = 0; i < nums.size(); i++) {
        if (test.find(nums[i]) == test.end()) {
            // Not found. Add
            test[nums[i]] = 1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector nums = {1, 2, 3};
    bool ans = containsDuplicate(nums);
    std::cout << ans << std::endl;
}