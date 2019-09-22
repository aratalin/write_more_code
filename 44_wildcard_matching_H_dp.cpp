class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        if(n == 0) return m == 0;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        int now = 0;
        while(p[now] == '*'){
            dp[0][now + 1] = true;
            now ++;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};