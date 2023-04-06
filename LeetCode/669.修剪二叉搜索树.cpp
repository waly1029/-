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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return fixBST(root, low, high);
        
    }
    TreeNode* fixBST(TreeNode* node, int low, int high) {
        if(node==nullptr) return nullptr;
        if(node->val < low) {
            TreeNode* r = fixBST(node->right, low, high);
            return r;
        }
        if(node->val > high) {
            TreeNode* l = fixBST(node->left, low, high);
            return l;
        }

        node->left = fixBST(node->left, low, high);
        node->right = fixBST(node->right, low, high);

        return node;

    }
};
