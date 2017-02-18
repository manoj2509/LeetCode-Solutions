//
// Created by Mj on 2/8/2017.
//

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<sstream>
#include <iostream>

using namespace std;
string intToStr(int x) {
    ostringstream ss;
    ss << x;
    string inp = ss.str();
    return inp;
}
int solution(int X) {
    // write your code in C++14 (g++ 6.2.0)

    long long int max = 0;
    string inp = intToStr(X);
    int temp;
    string st;
    for (int i =0; i < inp.length() - 1; i++) {
        temp = ((int)inp[i] - 48) + ((int)inp[i] - 48);
        temp = temp / 2;
        st = inp.substr(0, i) + intToStr(temp) + inp.substr(i + 2, inp.length());
        if (max < stoi(st)) {
            max = stoi(st);
        }

    }
    return max;
}