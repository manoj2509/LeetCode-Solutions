//
// Created by Mj on 1/6/2017.
//
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    // iterate over the array and remove if the matching element is found.
    std::vector< int >::iterator it = nums.begin();
    while (it != nums.end()) {
        if (*it == val) {
            nums.erase(it);
        } else {
            it++;
        }
    }
    return nums.size();
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int ans = removeElement(nums, val);

    std::cout << "Ans: " << ans;
}
