//
// Created by Mj on 12/30/2016.
//

#include <vector>
#include <iostream>
#include <algorithm>

int maxArea(std::vector < int >& height) {
    // The BRUTE FORCE method. takes O(n^2). Which is not good.
//    int area, h1, h2;
//    int maxi = 0;
//    for (int i = 0; i < height.size() - 1; i++) {
//        h1 = height[i];
//        for (int j = i + 1; j < height.size(); j++) {
//            h2 = height[j];
//            area = std::min(h1, h2) * (j - i);
//            if (area > maxi) {
//                maxi = area;
//            }
//        }
//    }
//    return maxi;
    // The improved version which is O(n).
    int area, h1, h2;
    int maxi = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i != j) {
        h1 = height[i];
        h2 = height[j];
        area = (j - i) * std::min(h1, h2);
        if (area > maxi) {
            maxi = area;
        }
        if (h1 > h2) {
            j--;
        } else {
            i++;
        }
    }
    return  maxi;
}

int main() {
    std::vector < int > v = {1, 1};
    int max = maxArea(v);
    std::cout << max;
}