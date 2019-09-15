class Solution {
private:
    map<string, int> idmap;
    map<int, map<int, double>> f;
    int ids;
    int add_node(string& x){
        if(idmap.count(x)) return idmap[x];
        ids ++;
        idmap[x] = ids;
        return ids;
    }
    void add_edge(int a, int b, double x){
        
        if(f.count(a) == 0) {
            f[a] = map<int, double>();
            f[a][a] = 1.0;
        }
        f[a][b] = x;
    }
    
    double bfs(int start, int end){        
        unordered_set<int>vis;
        queue<int> q;
        vis.insert(start);
        q.push(start);
        while(!q.empty()){
            int now = q.front(); q.pop();
            if(now == end) return f[start][now];
            for(auto next: f[now]){
                int y = next.first;
                
                if(vis.find(y)!= vis.end()) continue;
                vis.insert(y);
                double val = next.second * f[start][now] ;
                add_edge(start, y, val);
                add_edge(y, start, 1/ val);
                q.push(y);
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        ids = -1;
        for(int i = 0; i < equations.size(); i++){
            int x = add_node(equations[i][0]);
            int y = add_node(equations[i][1]);
            add_edge(x, y, values[i]);
            add_edge(y, x, 1 / values[i]);
        }
        vector<double> ans;
        for(auto query: queries){
            if(idmap.count(query[0]) == 0 || idmap.count(query[1]) == 0) {
                ans.push_back(-1.0);
                continue;
            }
            int x = idmap[query[0]];
            int y = idmap[query[1]];
            ans.push_back(bfs(x, y));
        }
        return ans;
    }
};