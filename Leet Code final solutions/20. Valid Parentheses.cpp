//
// Created by Mj on 12/17/2016.
//

#include <iostream>
#include <stack>

int main() {
    std::string s = ")";
    // create a stack
    // keep adding for ({[. Pop for else.
    // if popped is reverse of it, true else false.
    bool ans = false;
    bool flag = false;
    std::stack <char> stack1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack1.push(s[i]);
        } else {
            char temp;
            if (!stack1.empty()) {
                temp = stack1.top();
                stack1.pop();
                if (temp == '(' &&s [i] != ')') {
                    flag = true;
                    break;
                } else if (temp == '{' && s[i] != '}') {
                    flag = true;
                    break;
                } else if (temp == '[' &&s[i] != ']') {
                    flag = true;
                    break;
                }
            } else {
                flag = true;
                break;
            }
        }
    }
    if (!flag) {
        ans = stack1.empty();
        std::cout << "went here" ;
    }
    if (ans == 1) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}