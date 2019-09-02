class Solution {
private:
    vector<vector<int>>ans;
    map<int, int>mask2pos;
    inline int lower_bit_pos(int mask){
        int p = mask & (-mask);
        return mask2pos[p];
    }
    void dfs(vector<int>&nums, vector<int>& now_per, int mask){
        if(mask == 0){
            ans.push_back(now_per);
            return;
        }
        int now_mask = mask;
        while(now_mask){
            int p = lower_bit_pos(now_mask);
            now_mask ^= (1<<p);
            now_per.push_back(nums[p]);
            dfs(nums, now_per, mask ^ (1 << p));
            now_per.pop_back();
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        int n = nums.size();
        int mask = 0;
        while(n--){
            mask<<=1; mask |= 1;
            mask2pos[1<<n] = n;
        }
        vector<int> now_per;
        dfs(nums, now_per, mask);
        return ans;
    }
};