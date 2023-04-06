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
    int getMinimumDifference(TreeNode* root) {
        process(root);
        return diff;
    }

    void process(TreeNode* cur) {
        if(!cur) return;

        process(cur->left);
        // 开始回溯之前pre一直为nullptr， 跟在cur之后
        // 第一次到达最左节点之前pre为nullptr，不进入if语句
        if(pre!=nullptr)
            diff = min(diff, abs(pre->val - cur->val));
        pre = cur;
        process(cur->right);
    }
private:
    int diff = INT32_MAX;
    TreeNode* pre;
};
