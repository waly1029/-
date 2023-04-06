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
        // return postOrder(root, p, q);

        return solution(root, p, q);
    }

    TreeNode* solution(TreeNode* node, TreeNode* p, TreeNode* q) {
        while(node) {
            if(node->val>p->val && node->val>q->val)
                node = node->left;
            else if(node->val<p->val && node->val<q->val)
                node = node->right;
            else return node;
        }
        return nullptr;
    }

    TreeNode* postOrder(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return nullptr;
        if(node->val>p->val && node->val>q->val) {
            TreeNode* left = postOrder(node->left, p, q);
            if(left) return left;
        }
        if(node->val<q->val && node->val<p->val) {
            TreeNode* right = postOrder(node->right, p, q);
            if(right) return right;
        }
        return node;
    }
};
