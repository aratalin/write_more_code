class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, INT_MAX-1);
        dp[0] = 0;
        
        int max_sq = int(sqrt(n));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        
        
        return dp[n];
    }
};

class Solution {
    
public:
    vector<int>dp; 
    int dfs(int n){
        if(dp[n] != INT_MAX-1) return dp[n];
        int t = int(sqrt(n));
        if(t * t == n) {
            dp[n] = 1; return 1;
        }
        for(int i = t; i >= 1; i--){
            dp[n] = min(dp[n], dfs(n - i * i) + 1);
        }
        //printf("%d %d %d\n", n, dp[n], t);
        return dp[n];
    }
    int numSquares(int n) {
        dp = vector<int>(n + 1, INT_MAX-1);
        dp[0] = 0; dp[1] = 1;
        return dfs(n);
    }
};