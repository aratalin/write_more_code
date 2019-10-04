class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size() == 0) return s2 == s3;
        if(s2.size() == 0) return s1 == s3;
        int n = s1.size(), m = s2.size(); 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        int i = 0;
        while(i < s1.size() && s1[i] == s3[i]) {
            dp[i + 1][0] = 1;
            i++;
        }
        i = 0;
        while(i < s2.size() && s2[i] == s3[i]) {
            dp[0][i+1] = 1;
            i++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s3[i+j - 1]){
                    dp[i][j] |= dp[i-1][j];
                }
                if(s2[j- 1] == s3[i+j-1]){
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }
        
        return dp[n][m];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size() == 0) return s2 == s3;
        if(s2.size() == 0) return s1 == s3;
        int n = s1.size(), m = s2.size(); 
        vector<vector<int>> dp(2,vector<int>(m+1 ,0));
        dp[0][0] = 1;
        int i = 0;
        while(i < s2.size() && s2[i] == s3[i]) {
            dp[0][i + 1] = 1;
            i++;
        }
        i = 0;
        for(int i = 1; i <= n; i++){
            if(s1[i-1] == s3[i-1]) dp[i&1][0] = dp[i&1^1][0];
            else dp[i&1][0] = 0;
            for(int j = 1; j <= m; j++){
                dp[i&1][j] = 0;
                if(s1[i-1] == s3[i+j - 1]){
                    dp[i&1][j] |= dp[i&1^1][j];
                }
                if(s2[j- 1] == s3[i+j-1]){
                    dp[i&1][j] |= dp[i&1][j - 1];
                }
            }
        }
        
        return dp[n&1][m];
    }
};