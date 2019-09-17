class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
          if(a[0] == b[0]) return a[1] > b[1];
          return a[0] < b[0];
     }  
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(people.size(), vector<int>(2, -1));
        
        for(auto p : people){
            //printf("%d %d\n", p[0], p[1]);
            int e = p[1];
            for(int i = 0; i < people.size(); i++){
                if(ans[i][0] != -1) continue;
                if(e == 0){
                    ans[i] = p;
                    break;
                }
                e--;
            }
        }
        return ans;
    }
};