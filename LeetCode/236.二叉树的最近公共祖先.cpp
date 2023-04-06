/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return postOrder(root, p, q);
    }

    TreeNode* postOrder(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return nullptr;
        else if(node==p || node==q) return node;

        // ************注意返回值，每次都忘记这个递归函数的返回值************
        TreeNode* left = postOrder(node->left, p, q);
        TreeNode* right = postOrder(node->right, p, q);

        if(left && right) return node;
        else if(left && !right) return left;
        else if(!left && right) return right;
        else return nullptr;
    }
};
