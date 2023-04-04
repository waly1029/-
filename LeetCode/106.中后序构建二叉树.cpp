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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return nullptr;
        int rootVal = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootVal);

        if(postorder.size()==1) return root;

        int index = 0;
        for(index; index<inorder.size(); index++) {
            if(rootVal==inorder[index])
                break;
        }

        // 切数组
        // inorder
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        // cout << *(inorder.begin()+index-1) << ' ';
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
        // cout << *(inorder.end()-1);
        // postorder
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+index);
        vector<int> rightPostorder(postorder.begin()+index, postorder.end()-1);
        // cout << *(postorder.end()-2) << ' ';

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
