//
// Created by Mj on 1/29/2017.
//
#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    // find the starting point.
    if (nums.size() == 0) {
        return {-1, -1};
    }
    int beg = 0;
    int end = nums.size() - 1;
    int mid = 0;
    while (beg != end) {
        mid = (beg + end) / 2;
        if (nums[mid] >= target) {
            end = mid;
        } else {
            beg = mid + 1;
        }
    }
    mid = (beg + end) / 2;
    std::cout << "~~" << mid << std::endl;
    // Find the ending point.
    beg = 0;
    end = nums.size() - 1;
    int mid1;
    while (beg != end) {
        mid1 = ((beg + end) / 2) + 1;
        if (nums[mid1] <= target) {
            beg = mid1;
        } else {
            end = mid1 - 1;
        }
    }
    mid1 = ((beg + end) / 2);
    std::cout << "~~" << mid1 << std::endl;
    std::vector< int > ans;
    if (mid > mid1) {
        ans.push_back(-1);
        ans.push_back(-1);
    } else {
        if (nums[mid] == target) {
            ans.push_back(mid);
            ans.push_back(mid1);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
    }
    return ans;
}

int main () {
    std::vector< int > nums = {1, 3};
    int target = 1;
    std::vector< int > ans = searchRange(nums, target);
    std::cout << ans[0] << " ~~ " << ans[1];
}