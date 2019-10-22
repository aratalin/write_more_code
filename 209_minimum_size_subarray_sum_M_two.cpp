class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int now = 0, ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            now += nums[i];
            while(now - nums[l] >= s){
                now -= nums[l];
                l++;
            }
            if(now >= s){
                ans = min(ans, i - l + 1);
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};