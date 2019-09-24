class Solution {
public:
    vector<int> col;
    vector<pair<int, int>> now;
    vector<vector<string>> ans;
    vector<string> build(int n){
        vector<string> tmp = vector<string>(n, string(n, '.'));
        for(auto t: now){
            tmp[t.first][t.second] = 'Q';
        }
        return tmp;
    }
    bool dia(int row, int col){
        for(auto t: now){
            if(row - t.first == abs(col - t.second)) return true;
        }
        return false;
    }
    void dfs(int n, int id){
        if(id == n){
            ans.push_back(build(n));
            return;
        }
        for(int i = 0; i < n; i++){
            if(col[i] || dia(id, i)) continue;
            col[i] = 1;
            now.push_back(make_pair(id, i));
            dfs(n, id + 1);
            col[i] = 0;
            now.pop_back();
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        col = vector<int>(n, 0);
        dfs(n, 0);
        return ans;
    }
};