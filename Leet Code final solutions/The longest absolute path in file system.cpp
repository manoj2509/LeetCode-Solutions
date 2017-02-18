//
// Created by Mj on 2/4/2017.
//
#include <iostream>
#include <vector>
#include <stack>

std::string createName(std::stack< std::string >& dirs) {
    std::stack< std::string > temp = dirs;
    std::string ans = temp.top();
    temp.pop();
    while (!temp.empty()) {
        ans = temp.top().size() + "/" + ans;
        temp.pop();
    }
    return ans;
}
std::string longestFilePath(std::string inp) {
    // Iterate over the string and divide it into vectors.
    std::vector< std::string > parts;
    std::string temp;
    std::string ans = "";
    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == '\\' && inp[i + 1] == 'n') {
            parts.push_back(temp);
            temp = "";
            i++;
        } else {
            temp += inp[i];
        }
    }
    if (temp.length() > 0) {
        parts.push_back(temp);
    }
//    for (int i = 0; i < parts.size(); i++) {
//        std::cout << "^^" << parts[i] << std::endl;
//    }
    std::stack< std::string > dirs;
    int level = 0;
    dirs.push(parts[0]);
    level++;
    for (int i = 1; i < parts.size(); i++) {
        int j = 0;
        int noOfTabs = 0;
        while(parts[i][j] == '\\' && parts[i][j + 1] == 't') {
            noOfTabs++;
            j += 2;
        }
        std::string dirName = parts[i].substr((unsigned int) (noOfTabs * 2));
        if (dirs.size() > noOfTabs) {
            while (dirs.size() != noOfTabs) {
                dirs.pop();
            }
        }
        dirs.push(dirName);
        if (dirName.find(".") != std::string::npos) {
            // Means end of file has been encountered. Must get the length and store that.
            std::string tempName = createName(dirs);
            if (tempName > ans) {
                ans = tempName;
            }
//            std::cout << "~~" << temp << std::endl;
        }
    }
    return ans;
}
int main() {
    std::string shortString = "dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext";
    std::string longString = "dir\\n\\tsubdir1\\n\\t\\tfile1.ext\\n\\t\\tsubsubdir1\\n\\tsubdir2\\n\\t\\tsubsubdir2\\n\\t\\t\\tfile2.ext";

    std::string ans = longestFilePath(longString);
    std::cout << ans << std::endl;
}