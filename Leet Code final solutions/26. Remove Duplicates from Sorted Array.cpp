//
// Created by Mj on 1/6/2017.
//

#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    // Iterate using while.
    // And keep checking until the next value is equal to the current value.
    std::vector< int >::iterator it = nums.begin();
    while (it != nums.end()) {
        while (*it == *(it + 1) && (it + 1) != nums.end()) {
            std::vector<int>::iterator tempIt = it + 1;
            nums.erase(tempIt);
        }
        it++;
    }
    return nums.size();
}

int main() {
    std::vector< int > nums = {1, 1, 2};
    int ans = removeDuplicates(nums);
    std::cout << "Ans: " << ans << std::endl;
}