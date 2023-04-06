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
    TreeNode* searchBST(TreeNode* root, int val) {
        // 递归
        // 注意终止条件
        // if(!root || root->val==val) return root;

        // if(val < root->val)
        //     return searchBST(root->left, val);
        // if(val > root->val)
        //     return searchBST(root->right, val);

        // return nullptr;

        return process(root, val);
    }

    // 迭代
    TreeNode* process(TreeNode* root, int val) {
        // if(!root) return nullptr;

        TreeNode* res = root;
        while(res) {
            // if(val == res->val) return res;
            if(val < res->val)
                res = res->left;
            else if(val > res->val)
                res = res->right;
            else
                return res;
        }

        return nullptr;
    }
};
