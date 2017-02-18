//
// Created by Mj on 1/3/2017.
//
#include <iostream>
#include <cstring>

int strStr(std::string haystack, std::string needle) {
    int i = 0;
    if (haystack == needle || needle.length() == 0) {
        return 0;
    }
    if (haystack.length() < needle.length()) {
        return -1;
    }
    while (i < haystack.length()) {
        // convert to lower case before comparing.
        if (haystack[i] == needle[0]) {
            // The first characters meet. Now we check for matching the remaining ones.
            std::string hayTemp = haystack.substr(i, needle.length());
            if (hayTemp == needle) {
                return i;
            }
        }
        i++;

    }
    return -1;
}
int main() {
    std::string haystack = "Manoj Parihar";
    std::string needle = "Pari";
    int ret = strstr(haystack, needle);

    std::cout << haystack.length();
}
//(Dhanraj9461284508)