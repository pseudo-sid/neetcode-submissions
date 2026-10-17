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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(not root)
            return root;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while(not bfsQueue.empty()){
            
                TreeNode* node = bfsQueue.front();
                bfsQueue.pop();
                

                swap(node->left, node->right);
                if(node->left) bfsQueue.push(node->left);
                if(node->right) bfsQueue.push(node->right);
        }

        return root;
    }
};
