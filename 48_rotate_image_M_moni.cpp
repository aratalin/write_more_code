class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        vector<pair<int, int>> dir{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
        int n = matrix.size();
        for(int i = 0; i < (n >> 1); i++){
            int tmp = 0;
            for(int j = i; j < n - i - 1; j ++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n-i-1][n-j-1];
                matrix[n - i - 1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
};