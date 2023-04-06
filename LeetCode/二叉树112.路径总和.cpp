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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        // 开始递归之前已经默认有根节点，所以目标值减去根节点值
        return solution(root, targetSum-root->val);
    }

    bool solution(TreeNode* node, int targetSum) {
        // 叶子节点时候判断是否为目标值
        if(!node->left && !node->right && targetSum==0) return true;
        if(!node->left && !node->right && targetSum!=0) return false;

        if(node->left) {
            targetSum -= node->left->val;
            // 记得有返回值的递归函数
            if(solution(node->left, targetSum)) return true;
            targetSum += node->left->val;   // 回溯时值也要回溯

            // ||
            // ||
            // ||
            //  if(solution(node->left, targetSum-node->left->val)) return;
        }

        if(node->right) {
            targetSum -= node->right->val;
            if(solution(node->right, targetSum)) return true;
            targetSum += node->right->val;
        }
        return false;

    }
};
