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

// ****************分析五种情况****************
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delNode(root, key);
    }

    TreeNode* delNode(TreeNode* node, int key) {
        // ****五种情况****
        // 没找到节点
        if(!node) return nullptr;

        // 找到节点
        if(node->val==key) {
            // 保存删除节点释放内存
            TreeNode* deletedNode = node;
        // 叶子结点，左右空
            if(!node->left && !node->right) {
                return nullptr;
            }
        // 被删节点左不空右空
            if(node->left && !node->right)
                return node->left;
        // 被删节点左空右不空
            if(!node->left && node->right)
                return node->right;
        // 被删节点左右都不空
            if(node->left && node->right) {
                TreeNode* cur = node->right;
                while(cur->left) cur = cur->left;
                cur->left = node->left;
                return node->right;
            }

            delete deletedNode;
        }

        if(key < node->val) node->left = delNode(node->left, key);
        if(key > node->val) node->right = delNode(node->right, key);

        return node;

    }
};
