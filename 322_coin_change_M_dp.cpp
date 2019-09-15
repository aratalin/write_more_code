class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount; i++){
            for(auto j : coins){
                if(j > i) break;
                dp[i] = min(dp[i-j] + 1, dp[i]);
            }
        }
        if(dp[amount] == amount + 1) return -1;
        return dp[amount];
    }
};