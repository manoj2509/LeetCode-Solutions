//
// Created by Mj on 1/6/2017.
//
#include <iostream>
#include <vector>
// Question Extension: One duplicate is allowed, not more than that.
int removeDuplicates(std::vector<int>& nums) {
    bool dupFlag = false;
    std::vector< int >::iterator it = nums.begin();
    if (nums.size() <= 2) {
        return nums.size();
    }
    while(it != nums.end()) {
        if ((it + 1) != nums.end() && *it == *(it + 1)) {
            if (dupFlag) {
                std::vector< int >::iterator temp = it + 1;
                nums.erase(temp);
            } else {
                dupFlag = true;
                it++;
            }
        } else {
            dupFlag = false;
            it++;
        }

    }
    return nums.size();
}

int main() {
    std::vector< int > nums = {1, 1, 1};
    int len = removeDuplicates(nums);
    std::cout << "Ans: " << len;
}
