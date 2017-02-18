//
// Created by Mj on 1/4/2017.
//
#include <iostream>
#include <vector>

bool repeatedSubstringPattern(std::string str) {
    // start extracting patterns from strings and then comparing.
    // discard any comparisons that are not
    std::vector < std::string> comparators;
    for (int i = 1; i <= str.length() / 2; i++) {
        if (str[i] == str[0]) {
            std::string temp = str.substr(0, i);
            if (str.length() % temp.length() == 0) {
                comparators.push_back(temp);
            }
        }
    }
    // Now we have all comparators.
    for (int i = 0; i < comparators.size(); i++) {
        // checking if the main keyword can be made with this or not.
        if (str.length() % comparators[i].length() == 0) {
            // concatenate the string that much times and compare.
            std::string temp = comparators[i];
            int len = str.length() / comparators[i].length();
            for (int j = 1; j < len; j++) {
                temp += comparators[i];
            }
            std::cout << "Resultant String: " << temp << std::endl;
            if (temp == str) {
                return true;
            }
        }
    }
    for (int i = 0; i < comparators.size(); i++) {
        std::cout << comparators[i] << std::endl;
    }
    return false;
}

int main() {
    std::string str = "ababaababa";
    bool ans = repeatedSubstringPattern(str);

    std::cout << "Ans: " << ans << std::endl;
}