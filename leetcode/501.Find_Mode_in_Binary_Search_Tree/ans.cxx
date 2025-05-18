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
        if(!root) return root;
        map<int, int> record;

        search(root, record);

        vector<int> ans;
        int max_cnt = -1;
        for(auto& [val, count] : record) {
            max_cnt = max(max_cnt, count);
        }

        for(auto& [val, count] : record) {
            if(count == max_cnt){
                ans.push_back(val);
            }
        }
        return ans;
    }


    void search(TreeNode* here, map<int, int>& record) {
        if(!here) {
            return;
        }
        search(here->left, record);
        search(here->right, record);
        record[here->val]++;
    }
};