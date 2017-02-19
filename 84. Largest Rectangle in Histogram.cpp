//
// Created by Mj on 2/18/2017.
//
#include <iostream>
#include <vector>

int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    int mini, area = 0, maxArea = 0;
    for (int i = 0; i < n; i++) {
        mini = heights[i];
        for (int j = i; j < n; j++) {
            if (heights[j] < mini) {
                mini = heights[j];
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            area = mini * (j - i + 1);

        }
        if (area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

int main() {
    std::vector< int > heights = {1, 1};
    std::cout << largestRectangleArea(heights) << std::endl;
}