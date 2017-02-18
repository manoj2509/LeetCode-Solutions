#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    unordered_map<int, vector<int>> unordered_map;
    int toFind;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        unordered_map[nums[i]].push_back(i);
        toFind = target - nums[i];
        if (toFind == nums[i]) {
            if (unordered_map[toFind].size() > 1) {
                v.push_back(unordered_map[toFind][0]);
                v.push_back(unordered_map[toFind][1]);
                break;
            }
        } else {
            if (unordered_map.find(toFind) != unordered_map.end()) {
                cout << "Found!" << unordered_map[toFind][0];
                v.push_back(unordered_map[toFind][0]);
                v.push_back(unordered_map[nums[i]][0]);
                break;
            }
        }
    }
    return 0;
}