//
// Created by Mj on 1/18/2017.
//
// Given a set of 4 numbers, find the largest valid time that can be made from those numbers.
#include <vector>
#include <iostream>
#include <unordered_map>

int findLargest(std::vector< int > nums) {
    int maxTime = 0;
    int maxMinute = 0;
    int temp = 0;
    int minute1 = -1;
    int minute2 = -1;
    std::unordered_map< int, int > hoursToMinutes;
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4 ; j++) {
            minute1 = -1;
            int tempHour1 = nums[i]*10 + nums[j];
            int tempHour2 = nums[j]*10 + nums[i];
            if (tempHour1 < 24 && tempHour2 < 24) {
                if (tempHour1 > tempHour2) {
                    temp = tempHour1;
                } else {
                    temp = tempHour2;
                }
            } else if (tempHour1 > 24 && tempHour2 < 24) {
                temp = tempHour2;
            } else {
                temp = tempHour1;
            }
            if (temp < 24 && temp > maxTime) {
                // Find valid minute now.
                for (int k = 0; k < 4; k++) {
                    if (k != i && k != j) {
                        if (minute1 == -1) {
                            minute1 = k;
                            std::cout << k;
                        } else {
                            minute2 = k;
                            std::cout << k << std::endl;
                        }
                    }
                }
                int min1 = nums[minute1]*10 + nums[minute2];
                int min2 = nums[minute2]*10 + nums[minute1];
                if (min1 < 60 && min2 < 60) {
                    if (min2 > min1) {
                            maxTime = temp;
                            maxMinute = min2;

                    } else if (min1 >= min2) {
                            maxTime = temp;
                            maxMinute = min1;
                    }
                } else if (min1 >= 60 && min2 < 60) {
                    maxTime = temp;
                    maxMinute = min2;
                } else if (min2 >= 60 && min1 < 60) {
                    maxTime = temp;
                    maxMinute = min1;
                }
            }
        }
    }
    std::cout << maxTime << ":" << maxMinute << std::endl;
}
int main() {
    std::vector< int > nums = {1, 2, 3, 4};
    int time = findLargest(nums);
    std::cout << time;
}