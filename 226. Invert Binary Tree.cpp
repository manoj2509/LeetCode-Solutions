//
// Created by Mj on 2/22/2017.
//
#include <iostream>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    std::queue< TreeNode* > oldQueue;
    std::queue< TreeNode* > newQueue;
    // Step 1: Add all to queue.
    oldQueue.push(root);
    TreeNode* newRoot = new TreeNode(root->val);
    newQueue.push(newRoot);
    while (!oldQueue.empty()) {
        TreeNode* temp = oldQueue.front();
        if (temp->left) {

        }
    }
    // Step 2: One by one, store all in another tree node.
}

int main() {
    // Testing the function.
}