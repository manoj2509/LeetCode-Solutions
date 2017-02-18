//
// Created by Mj on 11/18/2016.
//

#include <vector>
#include <string>
#include <iostream>

int main () {
    std::string s = "";
    int numRows = 2;
    // Create by algorithms
    int index;
    std::string ans = "";
    int diff = (2*numRows) - 2;
    if (numRows > 1) {
        // For Row 1
        ans += s[0];
        index = diff;
        while (index < s.length()) {
            ans += s[index];
            index += diff;
        }
        // For row 2 - numRows-1
        int i = 1;
        int j = diff - 1;
        while (i != j) {
            int index1 = i;
            int index2 = j;
            while (index2 < s.length()) {
                // add to ans:
                ans += s[index1];
                ans += s[index2];
                index1 += diff;
                index2 += diff;
            }
            if (index1 < s.length()) {
                ans += s[index1];
            }
            i++;
            j--;
        }
        // For last row
        int index3 = numRows - 1;
        while (index3 < s.length()) {
            ans += s[index3];
            index3 += diff;
        }
    } else {
        ans = s;
    }
    std::cout << ans;
}