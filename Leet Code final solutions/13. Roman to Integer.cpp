//
// Created by Mj on 12/20/2016.
//

#include <iostream>
#include <unordered_map>

int main() {
    std::string s = "MMDCCCXXII";   // 2822
//    s = "IX";
    // 1 = I, 5 = V, 10 = X, 50 = L, 100 = C, 500 = D, 1000 = M.
    // extract one by one, from rear side.
    // if the next one is smaller than the current, minus it from the total. Else plus only.
    std::unordered_map <char, int> roman;
    int ans = 0;
    roman.insert({'I', 1});
    roman.insert(std::make_pair('V', 5));
    roman.insert(std::make_pair('X', 10));
    roman.insert(std::make_pair('L', 50));
    roman.insert(std::make_pair('C', 100));
    roman.insert(std::make_pair('D', 500));
    roman.insert(std::make_pair('M', 1000));
    // contains all the key value pairs now.
    for (int i = s.size() - 1; i >= 0; i--) {
        char temp = s[i];   // a char.
        std::unordered_map <char, int>::const_iterator iter;
        iter = roman.find(temp);
        // check for the next one too.
        if (i >= 1) {
            char next = s[i - 1];
            std::unordered_map <char, int>::const_iterator iterNext;
            iterNext = roman.find(next);
            if (iter->second > iterNext->second) {
                ans = ans + iter->second - iterNext->second;
                i--;
            } else {
                ans += iter->second;
            }
        } else {
            ans += iter->second;
        }
    }
    std::cout << ans;
}