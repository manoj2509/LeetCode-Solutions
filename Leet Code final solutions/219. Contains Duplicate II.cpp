//
// Created by Mj on 2/1/2017.
//

#include <iostream>
#include <vector>
#include <unordered_map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map< int, std::vector< int >> test;
    for (int i = 0; i < nums.size(); i++) {
        if (test.find(nums[i]) == test.end()) {
            // Not found. Add
            std::vector< int > temp = {i};
            test[nums[i]] = temp;
        } else {
            std::vector< int > lastPosV = test[nums[i]];
            int lastPos = lastPosV[lastPosV.size() - 1];
            test[nums[i]].push_back(i);
            std::cout << lastPos << "~~" << i << std::endl;
            if ((i - lastPos) <= k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector< int > nums = {-1, -1};
    bool ans = containsNearbyDuplicate(nums, 1);
    std::cout << ans << std::endl;
}