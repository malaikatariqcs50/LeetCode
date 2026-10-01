//Last Solved on: 1 Oct 2026, Thursday
//Last Solved in: 13 minutes
class Solution {
private:
    void dfs(int i, int sum, vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target){
        if(sum == target){
            res.push_back(cur);
            return;
        }
        if(sum > target || i >= candidates.size()){
            return;
        }
        cur.push_back(candidates[i]);
        dfs(i, sum+candidates[i], res, cur, candidates, target);
        cur.pop_back();
        dfs(i+1, sum, res, cur, candidates, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0, 0, res, cur, candidates, target);
        return res;
    }
};

//Trick:
//Choices: Take the same (stay at i, bcz reuse is allowed) or take the next (i+1)
//No duplicates: Previous are never visited again, only i+1 AND the input contains ditinct integers

//Trigger:
//All possible Combinations + constraints = backtrack