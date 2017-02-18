//
// Created by Mj on 11/16/2016.
//

#include <iostream>

int main() {
    std::string s = "dvdf";
    std::string subAns = "";
    std::string mainAns = "";

    for (int i = 0; i < s.length(); i++) {
        std::size_t pos = subAns.find(s[i]);
        if (pos == std::string::npos) {
            // not found in the ans. Add it as part of the ans
            subAns += s[i];
        } else {
            // found, need to reset sub-ans.
            if (subAns.length() > mainAns.length()) {
                mainAns = subAns;
            }
            subAns = subAns.substr(pos + 1);
            // so that only that part is removed that contains repeated character.
            subAns += s[i];
        }
    }
    if (subAns.length() > mainAns.length()) {
        mainAns = subAns;
    }
    std::cout << mainAns << " " << mainAns.length();
}