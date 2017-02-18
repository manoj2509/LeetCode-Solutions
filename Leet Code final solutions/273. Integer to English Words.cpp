//
// Created by Mj on 12/21/2016.
//

#include <iostream>
#include <unordered_map>
#include <vector>

std::string toWords(int num) {
    std::unordered_map <int, std::string> alphaNum = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
                                                      {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"},
                                                      {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
                                                      {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
                                                      {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
                                                      {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
                                                      {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
                                                      {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
                                                      {100, "Hundred"}};
    // Num < 1000 guaranteed. Not greater than that.
    bool hundred = false;
    if (num > 99) {
        hundred = true;
    }
    int temp;
    std::vector < std::string > tempAns;
    if (num <= 20) {
        return alphaNum[num];
    }
    if (num == 100) {
        return "One Hundred";
    }
    std::unordered_map < int, std::string >::iterator it = alphaNum.find(num);
    if (it != alphaNum.end()) {
        return alphaNum[num];
    }
    temp = num % 100;
    if (temp < 20) {
        tempAns.push_back(alphaNum[temp]);
        num = num / 100;
    }
    int divisor = 10;
    while (num != 0) {
        temp = num % divisor;
        if (temp >= 100) {
            tempAns.push_back(alphaNum[temp/100]);
        } else {
            tempAns.push_back(alphaNum[temp]);
        }
        num -= temp;
        divisor *= 10;
    }
    // Writing answer to words.
    std::string ans;
    for (int i = tempAns.size() - 1; i >= 0; i--) {
        std::cout << tempAns[i] << "--" << std::endl;
        if (tempAns[i].size() != 0) {
            if (i != tempAns.size() - 1) {
                ans += " " + tempAns[i];
            } else {
                ans += tempAns[i];
            }
        }
        if (i == tempAns.size() - 1 && hundred) {
            ans += " Hundred";
        }
    }
    return ans;

}
std::string numberToWords(int num) {
    int temp = num;
    std::string ans;
    // Now convert them using one by one in groups of three from end.
    // Converting the three numbers from end and putting that in the string.
    // Now when printing add the denominations in the middle. Or add send as string from here.
    if (num == 0) {
        return "Zero";
    }
    std::unordered_map <int, std::string> denominations = {{0, ""}, {1, "Thousand"}, {2, "Million"}, {3, "Billion"}};
    std::vector < int > smallNums;
    while (num > 0) {
        smallNums.push_back(num%1000);
        num = num / 1000;
    }
    std::string tempAns;
    for (int i = smallNums.size() - 1; i >= 0; i--) {
        tempAns = toWords(smallNums[i]);
        if (tempAns.size() != 0) {
            if (i != 0) {
                ans += tempAns + " " + denominations[i] + " ";
            } else {
                ans += tempAns;
            }
        }
    }
    ans.erase(ans.find_last_not_of(' ')+1);         //suffixing spaces
    return ans;
}
int main() {
    int num = 1000000;
    // group in 3 and then convert according to their denominations.
    // Ones, Tens, Hundreds, Thousands, Millions, Billions

    std::string ans = numberToWords(num);
    std::cout << ans;

}