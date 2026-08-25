/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Idea: recursive solution.

The diameter starting at a certain node is just the sum of the depths of both sides.
So, we can find the diameter by maxing the diameter of root, and the diameter of its
right and left nodes.

How to connect depth and diameter?

Recursively find depth of right and left. Once both depths are found, update the max_diameter variable.


*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        depth(root);
        return max_diameter;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        max_diameter = std::max(max_diameter, left_depth + right_depth);
        return std::max(left_depth, right_depth) + 1;
    }
private:
    int max_diameter = 0;
};
