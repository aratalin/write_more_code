class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i&1][0] = matrix[i][0] == '1';
            ans = max(dp[i&1][0], ans);
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == '0') {
                    dp[i & 1][j] = 0;
                }else{
                    dp[i & 1][j] = min(dp[i & 1 ^ 1][j], min(dp[i & 1 ^ 1][j - 1], dp[i & 1][j-1])) + 1;
                    ans = max(ans, dp[i&1][j]);
                }
            }
        }
        
        
        return ans * ans;
    }
};