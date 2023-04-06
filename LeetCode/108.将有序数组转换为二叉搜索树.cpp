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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }

    // 注意函数参数的技巧**********************************
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int mid = (l+r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, l, mid-1);
        node->right = buildBST(nums, mid+1, r);

        return node;

    }
};
