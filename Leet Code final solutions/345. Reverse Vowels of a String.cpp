//
// Created by Mj on 1/6/2017.
//

#include <iostream>

std::string reverseVowels(std::string s) {
    std::string ans = "";
    std::string vowels = "aeiouAEIOU";
    std::string portion = "";
    // Extract all vowels to another string.
    // Again iterate the string and copy all back in reverse order.
    for (int i = s.length() - 1; i >= 0; i--) {
        if (vowels.find(s[i]) != std::string::npos) {
            portion += s[i];
        }
    }
    // portion is all the vowels reversed.
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (vowels.find(s[i]) != std::string::npos) {
            ans += portion[count];
            count++;
        } else {
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    std::string inp = "a.";
    std::string ans = reverseVowels(inp);

    std::cout << ans;
}