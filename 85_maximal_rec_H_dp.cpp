class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        vector<int>h(m, 0);
        vector<int>l(m, -1);
        vector<int>r(m, m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            // update h
            for(int j = 0; j < m; j++){
                h[j] = matrix[i][j] == '1' ? h[j] + 1: 0;
            }
            
            // update l
            int l_0 = -1;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') l[j] = max(l_0, l[j]);
                else{
                    l[j] = -1;
                    l_0 = j;
                }
            }
            
            // update r and update ans
            int r_0 = m;
            for(int j = m - 1; j >= 0; j--){
                if(matrix[i][j] == '1') r[j] = min(r[j], r_0);
                else{
                    r_0 = j;
                    r[j] = m;
                }
                ans = max(ans, (r[j] - l[j] - 1) * h[j]);
            }
        }
        return ans;
    }
};