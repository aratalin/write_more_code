class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int s = nums.size();
        vector<int>tmp(s + 2, 1);
        for(int i = 0; i < s; i++){
            tmp[i+1] = nums[i];
        }
        
        vector<vector<int>> dp(s + 2, vector<int>(s + 2, 0));
        for(int len = 2; len <= s + 1; len++){
            for(int i = 0; i < s; i++){
                int j = i + len;
                if(j > s + 1) break;
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + tmp[k] * tmp[i] * tmp[j]) ;
                }
            }
        }
        
        return dp[0][s + 1];
    }
};