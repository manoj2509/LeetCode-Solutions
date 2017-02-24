//
// Created by Mj on 2/11/2017.
//
#include <iostream>
#include <queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode* root)
{
    if (root==NULL) {
        return 0;
    }
    int lastElement = root->val;
    std::queue< TreeNode* > queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode* temp = queue.front();
        if (temp->right) {
            queue.push(temp->right);
        }
        if (temp->left) {
            queue.push(temp->left);
        }
        lastElement = temp->val;
        queue.pop();
    }
    return lastElement;
}