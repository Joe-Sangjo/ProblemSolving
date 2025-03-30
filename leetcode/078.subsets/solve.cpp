class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ret;

        for(int i = 0; i < nums.size(); i++){
            ans(nums, ret, subset, i);
        }

        ret.push_back(subset);
        return ret;
    }
    
    void ans(const vector<int>& nums, vector<vector<int>>& ret, vector<int>& subset, int idx) {
        subset.push_back(nums[idx]);
        ret.push_back(subset);

        for(int i = idx + 1; i < nums.size() ;i++) {
            ans(nums, ret, subset, i);
        }

        subset.pop_back();
    }
};