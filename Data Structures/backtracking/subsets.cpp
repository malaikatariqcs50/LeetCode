class Solution {
    //Last Solved on: 28th Sept 2026
    //Last Solved in: 20 mins
private:
    void dfs(int start, vector<vector<int>>& res, vector<int>& cur,
             vector<int>& nums) {
        res.push_back(cur);

        for(int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(i + 1, res, cur, nums);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0, res, cur, nums);
        return res;
    }
};

//Trigger:
//Every possible subset -> no basecase but something(loop) is required to end
//No duplicates allowed + once started from something, don't need to go back ---->>>>> for(int i = start);