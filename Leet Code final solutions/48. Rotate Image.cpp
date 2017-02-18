//
// Created by Mj on 1/18/2017.
//

#include <vector>
#include <iostream>

void printMatrix(std::vector< std::vector< int > > matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void rotate(std::vector< std::vector< int > > matrix) {
    int n = matrix.size();
    int temp;
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i - 1];
            matrix[j][n-i - 1] = temp;
        }
    }
    printMatrix(matrix);
}
int main() {
    std::vector < int > row1 = {0, 1, 2, 3};
    std::vector < int > row2 = {4, 5, 6, 7};
    std::vector < int > row3 = {8, 9, 10, 11};
    std::vector < int > row4 = {12, 13, 14, 15};
    std::vector< std::vector< int > > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    printMatrix(matrix);
    rotate(matrix);
}