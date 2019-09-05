class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (min(n, m) == 0) return max(n, m);
        
        vector<vector<int>> dp(2, vector<int>(m + 1, INT_MAX >> 1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) dp[0][i] = i;
        for(int i = 1; i <= n; i++){
            dp[i & 1][0] = i;
            for(int j = 1; j <= m; j++){
                dp[i & 1][j] = dp[i&1^1][j-1] + (word1[i-1] != word2[j-1]);
                dp[i & 1][j] = min(dp[i & 1][j], dp[i & 1 ^ 1][j] + 1);
                dp[i & 1][j] = min(dp[i & 1][j-1] + 1, dp[i & 1][j]);
            }
        }
        return dp[n & 1][m];
    }
};