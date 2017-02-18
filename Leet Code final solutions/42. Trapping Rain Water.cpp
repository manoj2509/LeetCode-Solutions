//
// Created by Mj on 12/30/2016.
//

#include <iostream>
#include <vector>

int waterStored(int startPt, int endPt, std::vector < int > height) {
    int area = 0;
    int mini = std::min(height[startPt], height[endPt]);
    area = mini * (endPt - startPt - 1);
    for (int i = startPt + 1; i < endPt; i++) {
        if (height[i] < mini) {
            area -= height[i];
        } else {
            area -= mini;
        }
    }
    return area;
}
int trap(std::vector < int > & height) {
    int i = 0;
    int n = height.size();
    int startPt;
    int endPt;
    int ans = 0;
    while (i < n) {
        // Getting the starting point and end points for getting water stacked between them.
        if (height[i + 1] < height[i]) {
            startPt = i;
            std::cout << "St Pt." << startPt << std::endl;
            i++;
            // Finding an endpoint.
            while (height[i] < height[startPt]) {
                i++;
            }
            if (i < n) {
                // maxima found that won't go beyond this point.
                endPt = i;
                // Calculate for this part.
                std::cout << "End Pt*" << endPt << std::endl;
                ans += waterStored(startPt, endPt, height);
            } else {
                // If we don't find we take the maximum among minimums.
                i = startPt + 1;
                endPt = i;
                while (i < n ) {
                    if (height[endPt] < height[i]) {
                        endPt = i;
                    }
                    i++;
                }
                i = endPt;
                std::cout << "End Pt" << endPt << std::endl;
                ans += waterStored(startPt, endPt, height);
            }
        } else {
            i++;
            std::cout << "1a" << std::endl;
        }
    }
    return ans;
}

int main () {
    std::vector < int > height = {2,8,5,5,6,1,7,4,5};
    int ans = trap(height);
    std::cout << ans << std::endl;
}