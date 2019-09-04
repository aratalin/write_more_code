class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(m + 1, 2147483647));
        dp[1][0] = 0;
        for(int i = 0; i < n; i++){
            int last = i & 1 ^ 1;
            dp[i & 1][0] = dp[last][0] + grid[i][0];
            for(int j = 1; j < m; j++){
                dp[i & 1][j] = min(dp[last][j], dp[i & 1][j-1]) + grid[i][j];
            }
        }
        return dp[(n-1) & 1][m-1];
    }
};