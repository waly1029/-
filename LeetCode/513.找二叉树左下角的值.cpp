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
    int maxDepth = INT32_MIN;
    int res;
    int findBottomLeftValue(TreeNode* root) {
        // return solution(root);

        solution2(root, 1);
        return res;
    }
    // 递归法
    void solution2(TreeNode* node, int depth) {
        // 终止条件，叶子节点
        if(!node->left && !node->right) {
            if(depth>maxDepth) {
                maxDepth = depth;
                res = node->val;
            }
            return;
        }

        // 遍历左
        if(node->left) {
            depth++;
            solution2(node->left, depth);
            depth--;
        }
        // 遍历右
        if(node->right) {
            depth++;
            solution2(node->right, depth);
            depth--;
        }
        return;
    }

    // 迭代法
    int solution(TreeNode* node) {
        queue<TreeNode*> que;
        if(node) que.push(node);

        int res = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                TreeNode* cur = que.front(); que.pop();
                res = cur->val;

                if(cur->right) que.push(cur->right);
                if(cur->left) que.push(cur->left);
            }
        }
        return res;
    }
};
