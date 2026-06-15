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
        pair<int, bool> left = height_and_balanced(root->left);
        if(not left.second)
            return {-1, false};
        pair<int, bool> right = height_and_balanced(root->right);
        int height = 1 + max(left.first, right.first);
        bool balanced = (abs(left.first - right.first) <= 1) and left.second and right.second;
        return {height, balanced};
    }
public:
    bool isBalanced(TreeNode* root) {
        return height_and_balanced(root).second;
    }
};
