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
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);

        return root;
    }

    void inorder(TreeNode* node) {
        if(node==nullptr) return;

        inorder(node->right);
        node->val += pre;
        pre = node->val;
        inorder(node->left);
    }


private:
    int pre = 0;
};
