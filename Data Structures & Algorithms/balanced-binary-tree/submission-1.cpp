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

class Solution {
    pair<int, bool> height_and_balanced(TreeNode* root){
        if(not root)
            return {0, true};
        auto [left_height, left_balanced] = height_and_balanced(root->left);
        if(not left_balanced)
            return {-1, false};
        auto [right_height, right_balanced] = height_and_balanced(root->right);
        int height = 1 + max(left_height, right_height);
        bool balanced = (abs(left_height - right_height) <= 1) and left_balanced and right_balanced;
        return {height, balanced};
    }
public:
    bool isBalanced(TreeNode* root) {
        return height_and_balanced(root).second;
    }
};
