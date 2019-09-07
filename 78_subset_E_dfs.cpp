class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int> &now_sub, int now_pos){
        if(nums.size() == now_pos) {
            ans.push_back(now_sub);
            return;
        }
        dfs(nums, now_sub, now_pos + 1);
        now_sub.push_back(nums[now_pos]);
        dfs(nums, now_sub, now_pos + 1);
        now_sub.pop_back();
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> now_sub;
        dfs(nums, now_sub, 0);
        return ans;
    }
};