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

    int maxStraightPath(TreeNode* node) {
        static std::unordered_map<TreeNode*, int> straight_sums;
        if (!node) return 0;
        auto itr = straight_sums.find(node);
        if (itr != straight_sums.end()) return itr->second;
        int straight_sum = std::max(0, node->val+std::max(maxStraightPath(node->left), maxStraightPath(node->right)));
        straight_sums[node] = straight_sum;
        return straight_sum;
    }

    int maxPathSum(TreeNode* root) {
        int res = std::numeric_limits<int>::min();
        if (root->left) res = std::max(res, maxPathSum(root->left));
        if (root->right) res = std::max(res, maxPathSum(root->right));
        res = std::max(res, root->val + maxStraightPath(root->left) + maxStraightPath(root->right));
        return res;
    }
};
