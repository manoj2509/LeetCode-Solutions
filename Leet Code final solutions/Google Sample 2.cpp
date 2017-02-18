//
// Created by Mj on 2/8/2017.
//

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include<stack>
#include <string>
#include <iostream>

using namespace std;
int getLength(stack< string > dirs) {
    stack< string > temp = dirs;
    temp.pop();
    int len = temp.size();
    while( !temp.empty()) {
        len += temp.top().size();
        temp.pop();
    }
    return len;

}

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector< string > parts;
    string temp;
    int ans;
    int n = S.length();
    for (int i = 0; i < n; i++) {
        if (S[i] == '\n') {
            parts.push_back(temp);
            temp = "";
        } else {
            temp += S[i];
        }
    }
    if (temp.length() > 0) {
        parts.push_back(temp);
    }
     for (int i = 0; i < parts.size(); i++) {
     cout << "^^" << parts[i] << endl;
     }
    int level = 0;
    stack< string > dirs;
    dirs.push(parts[0]);
    level++;
    for (int i = 1; i < parts.size(); i++) {
        int j = 0;
        int noOfSpaces = 0;
        while(parts[i][j] == ' ') {
            noOfSpaces++;
            j ++;
        }
        std::string dirName = parts[i].substr((unsigned int) (noOfSpaces));
        if (dirs.size() > noOfSpaces) {
            while (dirs.size() != noOfSpaces) {
                dirs.pop();
            }
        }
        dirs.push(dirName);
        if (dirName.find(".jpeg") != std::string::npos || dirName.find(".gif") != std::string::npos || dirName.find(".png") != std::string::npos) {
            // Means end of file has been encountered. Must get the length and store that.
            int tempSize = getLength(dirs);
            if (tempSize > ans) {
                ans = tempSize;
            }
        }
    }
    return ans;
}

int main() {
    string inp = "dir1\\n dir11\\n dir12\\n  pic.jpeg\\n  dir121\\n  file1.txt\\ndir2\\n filename2.gif";
    cout << solution(inp) << endl;
}