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
    int sumOfLeftLeaves(TreeNode* root) {
        return process(root);
    }

    int process(TreeNode* node) {
        if(!node) return 0;
        if(!node->left && !node->right) return 0;
        int leftNum = process(node->left);
        if(node->left!=nullptr && node->left->left==nullptr
                               && node->left->right==nullptr)
            leftNum = node->left->val;
        int rightNum = process(node->right);
        int sum = leftNum + rightNum;
        return sum;
    }
};
