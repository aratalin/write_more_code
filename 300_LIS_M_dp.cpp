class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = 0;
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        if(nums.size() ==0) return 0;
        dp.push_back(INT_MIN);
        int len = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > dp[len]) {
                dp.push_back(nums[i]);
                len ++;
            }
            else{
                int l = 1, r = len;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(dp[mid] >= nums[i]) r = mid - 1;
                    else l = mid + 1;
                }
                dp[l] = nums[i];
            }
        }
        return len;
        
    }
};