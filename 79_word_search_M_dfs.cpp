class Solution {
private:
    int n, m;
    vector<pair<int, int>> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
    inline bool inmap(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool dfs(vector<vector<char>>& board, string word, int matched, int pos_x, int pos_y){

        if(board[pos_x][pos_y] != word[matched]) return false;
        if(matched + 1 == word.size()) return true;
        board[pos_x][pos_y] = '\0';
        for(auto dir : dirs){
            int x = pos_x + dir.first;
            int y = pos_y + dir.second;
            if(inmap(x, y)){
                if(dfs(board, word, matched + 1, x, y)) return true;
            }
        }
        board[pos_x][pos_y] = word[matched];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        n = board.size();
        if(n == 0) return false;
        m = board[0].size();
        if(m == 0) return false;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j++){
                if(dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};