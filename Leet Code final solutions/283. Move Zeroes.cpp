//
// Created by Mj on 1/6/2017.
//
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int count = 0;
    std::vector<int>::iterator it = nums.begin();
    while (it != nums.end()) {
        if (*it == 0) {
            count++;
            nums.erase(it);
        } else {
            it++;
        }
    }
    // Adding zeroes in the end.
    for (int i = 0; i < count; i++) {
        nums.push_back(0);
    }
}

int main() {
    std::vector< int > nums = {1, 0, 2};
    moveZeroes(nums);
    std::cout << "Ans: ";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
}