class Solution {
public:
    bool is_match(char s, char p){
        if(p == '.') return true;
        if (s == p) return true;
        return false;
    }
    bool isMatch(string s, string p) {
        // define dp[i][j]:　match(s[0...i-1], p[0...j-1]
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(is_match(s[i-1], p[j-1])) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*'){
                    if(is_match(s[i-1], p[j-2])){
                        dp[i][j] = dp[i-1][j-2] || dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j-2];
                    }
                }
            }
        }
        cout << dp[8][9];
        return dp[n][m];
    }
};