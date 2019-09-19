class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j + i < s.size(); j++){
                int pos = j + i;
                if(s[j] == s[pos]){
                    if(j + 1 >= pos - 1 || dp[j+1][pos-1]){
                        dp[j][pos] = 1;
                        ans ++;
                    }
                }                 
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += expand(s, i, i);
            ans += expand(s, i, i + 1);
        }
        return ans;
    }
    int expand(string &s, int i, int j){
        int ans = 0;
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i --; j ++;
            ans ++;
        }
        return ans;
    }
};