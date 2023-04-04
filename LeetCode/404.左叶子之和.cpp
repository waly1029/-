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
    // 后序遍历
    int process(TreeNode* node) {
        // 根节点为空返回0
        if(!node) return 0;

        // 叶子节点返回0,此时无法判断是否是左叶子
        if(!node->left && !node->right) return 0;

        // 后序遍历左节点,判断是否有做孩子，并且左孩子为叶子节点
        int leftNum = process(node->left);
        if(node->left && !node->left->left && !node->left->right)
            leftNum += node->left->val;

        // 后序遍历右节点
        int rightNum = process(node->right);

        return leftNum + rightNum;
    }
};
