//
// Created by Mj on 11/18/2016.
//

#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    // Construct a sorted array and then access the middle value.
    std::vector<int> newVector;
    std::vector<int>::iterator itr1 = nums1.begin();
    std::vector<int>::iterator itr2 = nums2.begin();
    while (itr1 != nums1.end() && itr2 != nums2.end()) {
        if (*itr1 < *itr2) {
            newVector.push_back(*itr1);
            ++itr1;
        } else {
            newVector.push_back(*itr2);
            ++itr2;
        }
    }
    if (itr1 != nums1.end()) {
        while (itr1 != nums1.end()) {
            newVector.push_back(*itr1);
            ++itr1;
        }
    }
    if (itr2 != nums2.end()) {
        while (itr2 != nums2.end()) {
            newVector.push_back(*itr2);
            ++itr2;
        }
    }
    int len = newVector.size();
    double median;
    if (len % 2 == 0) {
        median = (double (newVector[(len/2) - 1]) + double (newVector[len/2])) / 2;
    } else {
        median = (double) newVector[(len/2)];
    }
    std::cout << median;
//    for (std::vector<int>::iterator it = newVector.begin(); it != newVector.end(); it++) {
//        std::cout << *it << " ";
//    }
}