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
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        preOrder(root, path, res);
        return res;
    }

    void preOrder(TreeNode* root, vector<int>& path, vector<string>& res) {
        // 这是前序遍历，放在这里防止叶子节点无法加入path路径
        path.push_back(root->val);

        if(!root->left && !root->right) {
            string sPath;
            for(int i=0; i<path.size()-1; ++i) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            res.push_back(sPath);
            return;
        }

        if(root->left) {
            preOrder(root->left, path, res); 
            // 回溯时候弹出元素
            path.pop_back();
        }
        if(root->right) {
            preOrder(root->right, path, res);
            // 回溯时候弹出元素
            path.pop_back();
        }
    }
};
