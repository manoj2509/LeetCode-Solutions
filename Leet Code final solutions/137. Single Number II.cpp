//
// Created by Mj on 1/26/2017.
//
#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int x, res = 0;

    for(int i = 0; i < sizeof(int)*8; i++){
        x = 1 << i;
        int sum = 0;
        for(int j = 0; j < nums.size(); j++){
            if(x & nums[j]) sum++;
        }

        if(sum % 3) res = res | x;
    }

    return res;
}

int main () {
    std::vector< int > nums = {1, 1, 1, 2};
    std::cout << singleNumber(nums);

}