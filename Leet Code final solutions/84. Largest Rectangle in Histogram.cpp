//
// Created by Mj on 2/18/2017.
//
#include <iostream>
#include <vector>
#include <stack>

// this is using heuristics.
int largestRectangleArea(std::vector<int>& heights) {
    std::stack< int > index;
    int maxArea = 0;
    int n = heights.size();
    int i = 0;
    while (i < n) {
        if (index.empty() || heights[i] >= heights[index.top()]) {
            index.push(i++);
        } else {
            int topIndex = index.top();
            // We will keep on moving ahead, so that all the minimums will get removed.
            index.pop();
            int areaTemp = heights[topIndex] * (index.empty() ? i : (i - index.top() - 1));
            if (areaTemp > maxArea) {
                maxArea = areaTemp;
            }
        }
    }
    while (! index.empty()) {
        int topIndex = index.top();
        index.pop();
        int areaTemp = heights[topIndex] * (index.empty() ? i : (i - index.top() - 1));
        if (areaTemp > maxArea) {
            maxArea = areaTemp;
        }
    }
    return maxArea;
}
int largestRectangleAreaBrute(std::vector<int>& heights) {
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
    std::vector< int > heights = {1, 3, 2, 1, 2};
    std::cout << largestRectangleArea(heights) << std::endl;
}