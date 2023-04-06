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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // if(nums.size()==0) return nullptr;
        
        // int max = 0;
        // int maxIndex = 0;
        // for(int i=0; i<nums.size(); ++i) {
        //     if(max<nums[i]) {
        //         max = nums[i];
        //         maxIndex = i;
        //     }
        //     // max = max>nums[i] ? max:nums[i];
        //     // maxIndex = max>nums[i] ? maxIndex:i;
        // }
        // TreeNode* root = new TreeNode(max);

        // vector<int> leftV(nums.begin(), nums.begin()+maxIndex);
        // vector<int> rightV(nums.begin()+maxIndex+1, nums.end());

        // root->left = constructMaximumBinaryTree(leftV);
        // root->right = constructMaximumBinaryTree(rightV);

        // return root;

        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        // 找到数组中最大的值和对应的下标
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;
        // 最大值所在的下标左区间 构造左子树
        if (maxValueIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        // 最大值所在的下标右区间 构造右子树
        if (maxValueIndex < (nums.size() - 1)) {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};
