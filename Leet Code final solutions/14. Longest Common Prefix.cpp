//
// Created by Mj on 12/15/2016.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main() {
    vector<string> strs = {""};        // The output should be "ab"
    // point to the first char of all
    // compare all of them, if same, add to answer.
    // if not common, return the answer.
    string ans = "";
    int flag = 0;
    bool breakCondition = false;
    int ptr = 0;
    if (strs.size() != 0) {
        if (strs.size() == 1) {
            ans = strs[0];
        } else {
            while (flag != 1 && breakCondition == 0) {
                for (vector<string>::iterator i = strs.begin(); i != strs.end() - 1; i++) {
                    string temp = *i;
                    string temp2 = *(i +1);
                    if (temp.size() < ptr) {
                        flag = 1;
                        break;
                    }
                    cout << "--" << temp[ptr] << endl;
                    if (temp[ptr] != temp2[ptr]) {
                        breakCondition = true;
                        break;
                    }
                }
                if (flag == 0 && breakCondition == 0) {
                    ans += strs[0][ptr];
                }
                ptr++;
            }
        }
        cout << ans;
    }
    return 0;
}