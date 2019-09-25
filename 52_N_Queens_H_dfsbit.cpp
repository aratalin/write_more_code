class Solution {
public:
    int ans;
    void dfs(int n, int id, int col, int lc, int rc){
        if(id == n){
            ans ++;
            return;
        }
        for(int i = 0; i < n; i++){
            int ps = 1 << i;
            if( (col | lc | rc) & ps) continue;
            dfs(n, id + 1, col | ps, (lc | ps) << 1, (rc | ps) >> 1);
        }
    }
    
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        return ans;
    }
};