class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int ok = 0;
        queue<int>q;
        vector<int>deg(numCourses, 0);
        vector<vector<int>> gra(numCourses, vector<int>());
        for(auto pre: prerequisites){
            int x = pre[0], y = pre[1];
            deg[x] ++;
            gra[y].push_back(x);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(deg[i] == 0) {
                q.push(i);
                ok++;
            }
        }

        while(!q.empty()){
            int x = q.front(); q.pop();
            for(auto y: gra[x]){
                deg[y]--;
                if(deg[y] == 0){
                    ok ++;
                    q.push(y);
                }
            }
        }
        return ok == numCourses;
    }
};