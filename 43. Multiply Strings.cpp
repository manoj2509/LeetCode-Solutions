//
// Created by Mj on 2/1/2017.
//
#include <iostream>
#include <vector>
#include <sstream>

std::string numberToString ( int Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

int stringToNumber(std::string str) {
    int x;
    std::stringstream convert(str);
    convert >> x;
    return x;
}
std::string multiply(std::string num1, std::string num2) {
    if (stringToNumber(num1) == 0 || stringToNumber(num2) == 0) {
        return "0";
    }
    std::string zeroes = "";
    int tempAns;
    int mult, carry = 0;
    std::string tempString;
    std::vector< std::string > ans;
    for (int i = num1.length() - 1; i >= 0; i--) {
        // 0 = 48
        int oneNum = (int)num1[i] - 48;
        carry = 0;
        tempString = zeroes;
        for (int j = num2.length() - 1; j >= 0; j--) {
            int twoNum = (int)num2[j] - 48;
            mult = oneNum * twoNum;
            tempAns = (mult + carry) % 10;
            carry = (mult + carry) / 10;
            std::cout << "++" << tempAns << "==" << carry << std::endl;
            tempString = numberToString(tempAns) + tempString;
        }
        if (carry > 0) {
            tempString = numberToString(carry) + tempString;
        }
        ans.push_back(tempString);
        std::cout << tempString << "##" << std::endl;
        zeroes += "0";
    }
    int n = ans[ans.size() - 1].size();
    int tempSum;
    std::string ansString = "";
    carry = 0;
    for (int i = 0; i < n; i++) {
        tempSum = 0;
//        carry = 0;
        for (int j = 0; j < ans.size(); j++) {
            if ((ans[j].size() -1 - i) >= 0 && (ans[j].size() -1 - i) <= 110) {
                tempSum += (ans[j][ans[j].size() - 1 - i] - 48);
                std::cout << "@@" << ans[j][ans[j].size() - 1 - i] << "&& " << ans[j].size() -1 - i << std::endl;
            }
        }
        mult = (tempSum + carry) % 10;
        carry = (tempSum + carry) / 10;
        std::cout << "~~" << tempSum << "@@" << mult << "^^" << carry << std::endl;
        ansString  = numberToString(mult) + ansString;
    }
    if (carry > 0) {
        ansString  = numberToString(carry) + ansString;
    }
    std::cout << ansString << std::endl;
    return ansString;
}

int main() {
    std::cout << multiply("999", "0");
}