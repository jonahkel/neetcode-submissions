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
 Recursion:
 return max of:
    root + max straight path on right + max straight path on left
    if left isn't null, maxPathSum(left)
    if right isn't null, maxPathSum(right)
 
 Of course, maxPathSum and maxStraightPath are overlapping.

 maxStraightPath:
 If node is null, return 0
 if node in straight_sums return straight_sums[node]
 straight_sum = max(0, node->val + max(maxStraightPath(left, right)))
 straight_sums[node] = straight_sum
 */

class Solution {
public:

    int maxStraightPath(TreeNode* node, int& res) {
        if (!node) return 0;
        int left_sum = maxStraightPath(node->left, res);
        int right_sum = maxStraightPath(node->right, res);
        res = std::max(res, node->val + left_sum+right_sum);
        return std::max(0, node->val + std::max(left_sum, right_sum));
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val;
        maxStraightPath(root, res);
        return res;
    }
};
