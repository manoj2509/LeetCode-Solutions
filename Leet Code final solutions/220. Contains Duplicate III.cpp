//
// Created by Mj on 2/1/2017.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <map>
#include <set>

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
    // iterate and store all of them.
    // for each, retrieve all the entries where diff is at most k (from both sides)
    // if not found, then leave, if found then check for diff of last indices of both entries.
    // TODO remove Errors for large integers.
    std::set<long long> window;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k && i - k - 1 < nums.size()) window.erase(nums[i - k - 1]);
        auto it = window.lower_bound((long long)nums[i] - t);
        if (it != window.cend() && *it - nums[i] <= t) return true;
        window.insert(nums[i]);
    }
    return false;
}

int main() {
    std::vector< int > nums = {-1, -1};
    bool ans = containsNearbyAlmostDuplicate(nums, 1, 0);
    std::cout << ans << std::endl;
}