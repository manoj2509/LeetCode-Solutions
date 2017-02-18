//
// Created by Mj on 12/17/2016.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int main () {
    std::string digits = "22";
    // Iterate through the string. And concatenate the correct strings in the answer.
    std::vector <std::string> alphaNum = {"", "", "abc", "def", "ghi", "jkl", "mno", "prqs", "tuv", "wxyz"};
    std::vector <std::string> ans;
    if (digits.size() > 0) {
        ans = {""};
    }
    // Iterate through all the numbers. Convert them to int
    for (int i = 0; i < digits.size(); i++) {
        int index = digits[i] - '0';
        if (index < 0 || index > 9) {
//            return ans;
            exit(1);
        }
        std::vector <std::string> tempAns = {};
        for (int j = 0; j < ans.size(); j++) {
            // add new string to blank.
            for (int k = 0; k < alphaNum[index].size(); k++) {
                tempAns.push_back(ans[j] + alphaNum[index][k]);
            }
        }
        ans = tempAns;
        // return ans;
    }
}