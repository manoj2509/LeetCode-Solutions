//
// Created by Mj on 2/11/2017.
//
#include <iostream>
int static GLevel;
int static GElement;

void height(TreeNode* root, int level, bool leftFlag) {
    if (root != NULL) {
        if (leftFlag) {
            // check for values.
            if (level > GLevel) {
                GElement = root->val;
                GLevel = level;
            }
        }
        height(root->left, level + 1, true);
        height(root->right, level + 1, false);
    }
}
int findLeftMostNode(TreeNode* root)
{
    if (root==NULL)
        return 0;
    else
    {
        GElement = root->val;
        GLevel=  0;
        /* compute the height of each subtree */
        height(root, 0, true);

        /* use the larger one */
        return(GElement);
    }
}