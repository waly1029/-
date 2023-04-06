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

    // **************新节点可以在叶子插入*****************
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // return insert(root, val);
        return solution(root ,val);
    }

    TreeNode* solution(TreeNode* node, int val) {
        if(!node) return new TreeNode(val);
        TreeNode* root = node;
        while(root) {
            if(val < root->val) {
                if(root->left)
                    root = root->left;
                else {
                    root->left = new TreeNode(val);
                    break;
                }
            }
            else if(val > root->val) {
                if(root->right)
                    root = root->right;
                else {
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
        return node;
        
    }

    TreeNode* insert(TreeNode* node, int val) {
        if(!node) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if(val<node->val)
            node->left = insert(node->left, val);
        else if(val>node->val)
            node->right = insert(node->right, val);
        
        return node;
    }
};/**
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

    // ******************新节点可以在叶子插入*********************
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // return insert(root, val);
        return solution(root ,val);
    }

    TreeNode* solution(TreeNode* node, int val) {
        if(!node) return new TreeNode(val);
        TreeNode* root = node;
        while(root) {
            if(val < root->val) {
                if(root->left)
                    root = root->left;
                else {
                    root->left = new TreeNode(val);
                    break;
                }
            }
            else if(val > root->val) {
                if(root->right)
                    root = root->right;
                else {
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
        return node;
        
    }

    TreeNode* insert(TreeNode* node, int val) {
        if(!node) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if(val<node->val)
            node->left = insert(node->left, val);
        else if(val>node->val)
            node->right = insert(node->right, val);
        
        return node;
    }
};
