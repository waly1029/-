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
    vector<int> findMode(TreeNode* root) {
        // solution(root);
        // restult.push_back(mp.begin()->first);
        // cout << mp.begin()->first << ": " << mp.begin()->second << endl;
        // for(auto it=next(mp.begin()); it!=mp.end(); ++it) {
        //     cout << it->first << ": " << it->second << endl;
        //     if(it->second > mp[restult[0]]) {
                
        //         // for(int i=0; i<restult.size(); ++i) {
        //         //     restult.pop_back();
        //         // }
        //         restult.clear();
        //         restult.push_back(it->first);
        //     }else if(it->second == mp[restult[0]]) {
        //         restult.push_back(it->first);
        //     }
        // }
        // return restult;

        solution2(root);
        return result;
    }

    void solution2(TreeNode* node) {
        if(!node) return;

        // 左
        solution2(node->left);

        // 中
        if(!pre) count = 1;
        else if(pre->val == node->val) count++;
        else count = 1;
        pre = node;
        if(countMax==count) {
            result.push_back(node->val);
        }
        if(count>countMax) {
            countMax = count;
            result.clear();
            result.push_back(node->val);
        }

        // 右
        solution2(node->right);
    }

    // void solution(TreeNode* node) {
    //     if(!node) return;

    //     solution(node->left);
    //     mp[node->val]++;
    //     solution(node->right);
    // }

private:
    // map<int, int> mp;
    // vector<int> restult;

    TreeNode* pre = nullptr;
    int count = 0;
    int countMax = 0;
    vector<int> result;
        
};
