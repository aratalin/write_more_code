class Solution {
private:
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    int n, m;
    bool inmap(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void bfs(vector<vector<char>>& grid, int x, int y){
        queue<pair<int,int>> q;
        grid[x][y] = '0';
        q.push(make_pair(x, y));
        while(!q.empty()){
            auto now = q.front(); q.pop();
            int x = now.first, y = now.second;
            for(int i = 0; i < 4; i++){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(inmap(xx, yy) && grid[xx][yy] == '1'){
                    grid[xx][yy] = '0';
                    q.push(make_pair(xx, yy));
                }
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1') {
                    ans ++;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};