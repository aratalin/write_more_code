class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int x = mid / m;
            int y = mid - x * m;
            if(matrix[x][y] == target) return true;
            if(matrix[x][y] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};