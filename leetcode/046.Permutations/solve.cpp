class Solution {
public:
    vector<vector<int>> ret;
    int all_visited;
    vector<vector<int>> permute(vector<int>& nums) {
        all_visited = (1 << nums.size()) - 1;
        
        int visited = 0;
        vector<int> partial_permute;
        for(int i = 0; i < nums.size(); i++){
            partial_permute.push_back(nums[i]);
            visited |= (1 << i);
            ans(nums, partial_permute, visited);
            partial_permute.pop_back();
            visited &= ~(1 << i);
        }    

        return ret;
    }

    void ans(const vector<int>& nums, vector<int>& partial_permute, int& visited) {
        if(visited == all_visited) {
            ret.push_back(partial_permute);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!(visited & (1 << i))) {
                partial_permute.push_back(nums[i]);
                visited |= (1 << i);
                ans(nums, partial_permute, visited);
                partial_permute.pop_back();
                visited &= ~(1 << i);
            }
        }

    }
};