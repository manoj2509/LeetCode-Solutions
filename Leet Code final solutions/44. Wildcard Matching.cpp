//
// Created by Mj on 2/9/2017.
//
#include <iostream>
bool checkMatch(std::string s, std::string p, int i, int j) {
    std::cout << s[i] << "~~" << p[j] << std::endl;
    if (i > s.size() && j > p.size()) {
        std::cout << "Empty strings\n";
        return true;
    }
    if (i > s.size()) {
        return false;
    }
    if (s[i] == p[j]) {
        return checkMatch(s, p, i + 1, j + 1);
    }
    if (p[j] == '?') {
        return checkMatch(s, p, i + 1, j + 1);
    }
    if (p[j] == '*') {
        std::cout << "* found" << std::endl;
        if (s[i] != '\0') {
            return (checkMatch(s, p, i + 1, j) || checkMatch(s, p, i, j + 1) || checkMatch(s, p, i + 1, j + 1));
        }
        return checkMatch(s, p, i, j + 1);
    }
    if (s[i] != p[j]) {
        std::cout << "Different chars " << s[i] << " " << p[j] << std::endl;
        return false;
    }
}
bool isMatch(std::string s, std::string p) {
//    return checkMatch(s, p, 0, 0);
    // DP approach also takes up a large amount of time, so we go to greedy solution.
    // Idea is to check and move forward everytime and not go for options.
    int starIndex = -1;
    int indexString = -1;
    int i = 0;
    int j = 0;
    while (i < s.size()) {
        std::cout << s[i] << "~~" << p[j] << std::endl;
        if (p[j] == '?' || p[j] == s[i]) {
            i++;
            j++;
        } else if (j < p.size() && p[j] == '*') {
            starIndex = j;
            j++;
            indexString = i;
        } else if (starIndex >= 0) {
            j = starIndex + 1;
            indexString++;
            i = indexString;
            continue;
        } else return false;
    }
    while (j < p.size() && p[j] == '*') {
        j++;
        std::cout << "coming" << std::endl;
    }
    return j == p.size();
}

int main() {
    std::cout << isMatch("aa", "*");
}