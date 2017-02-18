//
// Created by Mj on 2/14/2017.
//
#include <iostream>
#include <vector>
#include <algorithm>

bool track(std::vector<std::vector<char>>& board, std::string word, int size, std::vector<std::vector< int >>& worm) {
    if (size == word.size()) {
        std::cout << "found\n";
        return true;
    }
    bool upAns = false, downAns = false, leftAns = false, rightAns = false;
    int lastX = worm[worm.size() - 1][0];
    int lastY = worm[worm.size() - 1][1];
    std::cout << "Track: " << lastX << "~" << lastY << std::endl;
    if (lastX != 0) {
        std::cout << "TrackU: " << board[lastX - 1][lastY] << "~" << word[size] << std::endl;
        std::vector< std::vector< int >> temp = {{lastX - 1, lastY}};
        if (std::search(worm.begin(), worm.end(), temp.begin(), temp.end()) == worm.end()) {
            if (board[lastX - 1][lastY] == word[size]) {
                worm.push_back(temp[0]);
                std::cout << "TrackU: " << lastX << "~" << lastY << std::endl;
                upAns = track(board, word, size + 1, worm);
                if (!upAns) {
                    worm.pop_back();
                }
            }
        }
    }
    if (lastX != (board.size() - 1)) {
        std::cout << "TrackD: " << board[lastX + 1][lastY] << "~" << word[size] << std::endl;
        std::vector< std::vector< int >> temp = {{lastX + 1, lastY}};
        if (std::search(worm.begin(), worm.end(), temp.begin(), temp.end()) == worm.end()) {
            if (board[lastX + 1][lastY] == word[size]) {
                worm.push_back(temp[0]);
                std::cout << "TrackD: " << lastX << "~" << lastY << std::endl;
                downAns = track(board, word, size + 1, worm);
                if (!downAns) {
                    worm.pop_back();
                }
            }
        }
    }
    if (lastY != 0) {
        std::cout << "TrackL: " << board[lastX][lastY - 1] << "~" << word[size] << std::endl;
        std::vector< std::vector< int >> temp = {{lastX, lastY - 1}};
        if (std::search(worm.begin(), worm.end(), temp.begin(), temp.end()) == worm.end()) {
            if (board[lastX][lastY - 1] == word[size]) {
                worm.push_back(temp[0]);
                std::cout << "TrackL: " << lastX << "~" << lastY << std::endl;
                leftAns = track(board, word, size + 1, worm);
                if (!leftAns) {
                    worm.pop_back();
                }
            }
        }
    }
    if (lastY != (board[0].size() - 1)) {
        std::cout << "TrackR: " << board[lastX][lastY + 1] << "~" << word[size] << std::endl;
        std::vector< std::vector< int >> temp = {{lastX, lastY + 1}};
        if (std::search(worm.begin(), worm.end(), temp.begin(), temp.end()) == worm.end()) {
            if (board[lastX][lastY + 1] == word[size]) {
                worm.push_back(temp[0]);
                std::cout << "TrackR: " << lastX << "~" << lastY << std::endl;
                rightAns = track(board, word, size + 1, worm);
                if (!rightAns) {
                    worm.pop_back();
                }
            }
        }
    }
    return upAns || downAns || leftAns || rightAns;
}
bool exist(std::vector<std::vector<char>>& board, std::string word) {
    bool ans = false;
    int rows = board.size();
    int columns = board[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j] == word[0]) {
                std::vector<std::vector< int >> wormVector;
                std::vector< int > temp = {i, j};
                wormVector.push_back(temp);
                std::cout << "Exist: " << i << "~" << j << std::endl;
                ans = track(board, word, 1, wormVector);
                if (ans) {
                    return ans;
                }
            }
        }
    }
    return ans;
}

int main() {
//    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::vector<std::vector<char>> board = {{'A', 'A'}};
    std::string word = "AAA";
    std::cout << exist(board, word);
}