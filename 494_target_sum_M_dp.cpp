class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        S = abs(S);
        int sum = 0;
        for(auto i: nums) sum += i;
        if(sum < S) return 0;
        nums.push_back(abs(S));
        sum += S;
        if(sum & 1) return 0;
        int mid = sum >> 1;
        vector<int>dp(mid + 1, 0);
        dp[0] = 1;
        for(auto i: nums){
            for(int j = mid; j >= i; j--){
                if(dp[j - i]) dp[j] += dp[j-i];
            }
        }
        
        return dp[mid] >> 1;
    }
};