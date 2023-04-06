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
    // bool isValidBST(TreeNode* root) {
    //     // 若中序遍历有序则是
    //     // 根据中序规则判断
    //     vector<int> res;
    //     process(root, res);
    //     for(auto x: res) cout << x;
    //     for(int i=0; i<res.size()-1; ++i)
    //         if(res[i]>res[i+1] || res[i]==res[i+1])
    //             return false;
    //     return true;
    // }
    // void process(TreeNode* node, vector<int>& res) {
    //     if(!node) return;
    //     process(node->left, res);
    //     res.push_back(node->val);
    //     process(node->right, res);
    // }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        bool left = isValidBST(root->left);
        if(pre!=nullptr && pre->val>=root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);

        return left&&right;
    }
private:
    TreeNode* pre;
};
