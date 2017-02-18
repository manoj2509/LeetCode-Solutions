//
// Created by Mj on 1/27/2017.
//
#include <iostream>
#include <vector>
#include <algorithm>

void swap(int &tempIt, int &it) {
    int temp = tempIt;
    tempIt = it;
    it = temp;
}
void nextPermutation(std::vector<int>& nums) {
    if (nums.size() > 1) {
        std::vector< int >::iterator it = nums.end() - 2;
        while ((*it) >= *(it + 1) && it != nums.begin()) {
            it--;
        }
        if (it == nums.begin() && (*it) >= *(it + 1)) {
            // reverse the vector.
            std::reverse(nums.begin(), nums.end());
        } else {
            std::cout << *it << std::endl;
            // find next bigger number and bring to front.
            std::vector< int >::iterator temp = it + 2;
            std::vector< int >::iterator maxi = it + 1;
            while (temp != nums.end()) {
                if (*temp < *maxi && *temp > *it) {
                    maxi = temp;
                }
                temp++;
            }
            swap(*it, *maxi);
            it++;
            while (it != nums.end() - 1) {
                std::vector< int >::iterator mini = it;
                temp = it + 1;
                while (temp != nums.end()) {
                    if (*temp < *mini) {
                        mini = temp;
                    }
                    temp++;
                }
                swap(*it, *mini);
                it++;
            }
        }
    }
}
int main() {
    std::vector< int > nums = {2, 3, 1};
    // if sorted in decreasing order, reverse the list.
    // Find max and shift to right.
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}