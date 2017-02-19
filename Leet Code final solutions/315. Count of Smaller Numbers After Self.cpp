//
// Created by Mj on 2/8/2017.
//
#include <iostream>
#include <vector>
#include <set>

std::vector<int> countSmaller(std::vector<int>& nums) {
    // Set can also be used, but here we choose a vector to save us from the insertion time used in set.
    // so we use a vector and then retrieve from it.
    std::vector<int> db;
    std::vector<int> result(nums.size());
    for(int i = nums.size()-1; i >= 0; i--)
    {
        auto it = lower_bound(db.begin(), db.end(), nums[i]);
        result[i] = it - db.begin();
        db.insert(it, nums[i]);
    }
    return result;
}

int main() {
    std::vector< int > nums = {2, 0, 1};
    std::vector< int > ans = countSmaller(nums);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}