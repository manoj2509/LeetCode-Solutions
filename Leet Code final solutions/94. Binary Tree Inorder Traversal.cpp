//
// Created by Mj on 2/21/2017.
//
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Used stack in this approach.
// Added all the central nodes in array, then iterating them one by one.
std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack< TreeNode* > stack;
    std::vector< int > ans;
    TreeNode* current = root;
    bool done = false;
    while (!done) {
        // checking if there is anything in the left, we iterate until we find all of the left nodes.
        if (current) {
            stack.push(current);
            current = current->left;
        } else {
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();
                ans.push_back(current->val);
                current = current->right;
            } else {
                done = true;
            }
        }
    }
    return ans;
}