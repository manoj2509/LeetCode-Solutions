//
// Created by Mj on 12/16/2016.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    vector<int> nums = {-1, 0, 1, 1, 2, 2, -1, -3};
    // Brute force, iterate through all possible solutions.
    // Or sort the list first. Then iterate to check for zeros.
    vector< vector < int > > ans;
    vector < int > tempAns;
    int sum;
    if (nums.size() < 3) {
//        return ans;
        return 0;
    }
    sort ( nums.begin(), nums.end() );  // Sort it so that we can find numbers.
    for (vector <int>::iterator i = nums.begin(); i != nums.end(); i++) {
        // i has the number;
        if (*i > 0) {
            break;
        }
        // To avoid repetitions.
        if (i > nums.begin() && *i == *(i - 1)) {
            continue;
        }
        vector <int>::iterator j = i + 1;
        vector <int>::iterator k = nums.end() - 1;
        while (j < k) {
            sum = *i + *j + *k;
            if (sum == 0) {
                tempAns = {};       // empty the temporary answer.
                tempAns.push_back(*i);
                tempAns.push_back(*j);
                tempAns.push_back(*k);
                cout << *i << *j << *k << endl;
                ans.push_back(tempAns);
                j++;
                while (*j == *(j - 1) ) {
                    j++;
                }
                k--;
                while (*k == *(k + 1)) {
                    k--;
                }
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
    return 0;
}