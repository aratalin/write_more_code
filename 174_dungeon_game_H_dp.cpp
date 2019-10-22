class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) return 0;
        
        int n = dungeon.size(), m = dungeon[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        
        if(dungeon[n-1][m-1] >= 0) dp[n-1][m-1] = 0;
        else dp[n-1][m-1] = - dungeon[n-1][m-1];
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i < n - 1){
                    dp[i][j] = dp[i+1][j] - dungeon[i][j];
                }
                if(j < m - 1){
                    dp[i][j] = min(dp[i][j], dp[i][j+1] - dungeon[i][j]);
                }
                dp[i][j] = max(0, dp[i][j]);
            }
        }
        return dp[0][0] +1;
    }
};