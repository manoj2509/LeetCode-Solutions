//
// Created by Mj on 12/31/2016.
//

#include <iostream>
#include <vector>

std::vector< int > productExceptSelf(std::vector< int >& nums) {
    // swipe from left. keep multiplying upto that index. Then swipe from right and repeat same.
    std::vector < int > ans;
    int begTemp = 1;
    ans.push_back(begTemp);
    for (int i = 1; i < nums.size(); i++) {
        begTemp *= nums[i - 1];
        ans.push_back(begTemp);
    }
    int endTemp = 1;
    for (int i = ans.size() - 1; i >= 0; i--) {
        ans[i] *= endTemp;
        endTemp *= nums[i];
    }
    return ans;
}
int main() {
    std::vector < int > nums = {1,2,3,4};
    std::vector < int > ans = productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size() - 1) {
            std::cout << ans[i] << ", ";
        } else {
            std::cout << ans[i] << std::endl;
        }
    }
}