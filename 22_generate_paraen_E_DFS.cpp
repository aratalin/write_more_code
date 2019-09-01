class Solution {
private:
    vector<string>ans;
    void dfs(int n_l, int n_r, int n, string &tmp_string){
        if(n_l == n && n_r == n){
            ans.push_back(tmp_string);
            return;
        }
        if (n_l < n){
            tmp_string[n_l + n_r] = '(';
            dfs(n_l + 1, n_r, n, tmp_string);
        }
        if(n_l > n_r){
            tmp_string[n_l + n_r] = ')';
            dfs(n_l, n_r + 1, n, tmp_string);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return ans;
        string tmp_string(n*2 + 1, '\0');
        this->dfs(0, 0, n, tmp_string);
        return ans;
    }
};