class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, vector<int> &now_comb, int now_idx, int now_sum, int target){
        if(now_idx == candidates.size()) return;
        dfs(candidates, now_comb, now_idx + 1, now_sum, target);
        if(candidates[now_idx] == target - now_sum){
            now_comb.push_back(candidates[now_idx]);
            ans.push_back(now_comb);
            now_comb.pop_back();
        }else if(candidates[now_idx] < target - now_sum){
            now_comb.push_back(candidates[now_idx]);
            dfs(candidates, now_comb, now_idx, now_sum + candidates[now_idx], target);
            now_comb.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> now_comb;
        dfs(candidates, now_comb, 0, 0,target);
        return ans;
    }
};