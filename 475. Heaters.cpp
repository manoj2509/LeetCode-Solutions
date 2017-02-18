//
// Created by Mj on 2/17/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    if (heaters.size() < 1) {
        return 0;
    }
    int maxRad, temp1, temp2;
    int tempRad;
    std::vector< int >::iterator lIter;
    int start = houses[0] - 1;
    int end = houses[houses.size() - 1] + 1;
    maxRad = (heaters[0] - start - 1);
    for (int i = 1; i < heaters.size(); i++) {
        tempRad = (heaters[i] - heaters[i - 1]) / 2;
        lIter = std::lower_bound(houses.begin(), houses.end(), (tempRad + heaters[i - 1]));
//        std::cout << *(lIter) << "@@\n";
        temp1 = *(lIter - 1) - heaters[i - 1];
        if (lIter != houses.end()) {
            temp2 = heaters[i] - *(lIter);
        } else {
            temp2 = 0;
        }
        tempRad = std::min(tempRad, std::max(temp1, temp2));
//        std::cout << tempRad << "$$\n";

        if (tempRad > maxRad) {
            maxRad = tempRad;
        }
    }
    tempRad = (end - heaters[heaters.size() - 1] - 1);
    if (tempRad > maxRad) {
        return tempRad;
    }
    return maxRad;
}

int main() {
    std::vector< int > houses = {1, 2, 3, 5, 15};
    std::vector< int > heaters = {2, 30};
    std::cout << findRadius(houses, heaters);
}