//
// Created by Mj on 2/7/2017.
//

#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int temp = a;
    a= b;
    b = temp;
}

std::vector<int> findDuplicates(std::vector<int>& num) {
    std::vector< int > nums = num;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    std::vector< int > ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main() {
    std::vector< int > nums = {4,3,2,7,8,2,3,1};
    std::vector< int > ans;
    ans = findDuplicates(nums);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}