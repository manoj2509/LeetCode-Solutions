//
// Created by Mj on 12/17/2016.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    vector<int> nums = {1, 1, 1, 1};
    int target = 0;
    // Brute force, iterate through all possible solutions.
    // Or sort the list first. Then iterate to check for zeros.
    vector< vector < int > > ans;
    vector < int > tempAns;
    int closestAns;
    int minDiff= INFINITY;
    int sum;
    if (nums.size() < 3) {
//        return ans;
        return 0;
    }
    sort ( nums.begin(), nums.end() );  // [-4, -1, 1, 2]
    for (vector <int>::iterator i = nums.begin(); i != nums.end(); i++) {
        // To avoid repetitions.
        if (i > nums.begin() && *i == *(i - 1)) {
            continue;
        }
        vector <int>::iterator j = i + 1;
        vector <int>::iterator k = nums.end() - 1;
        while (j < k) {
            sum = *i + *j + *k;
            // we have to look at distance +1 or -1 doesn't matter.
            if (abs(sum - target) < minDiff) {
                closestAns = sum;
                cout << closestAns << endl;
                minDiff = abs(sum - target);
            }
            if (sum - target < 0) {
                j++;
                while (*j == *(j - 1) ) {
                    j++;
                }
            } else {
                k--;
                while (*k == *(k + 1)) {
                    k--;
                }
            }
        }
    }
    return 0;
}