class Solution {

public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int start_p = intervals[0][0];
        int end_p = intervals[0][1];
        for(int i = 1; i < intervals.size() ; i++){
            if(intervals[i][0] > end_p){
                ans.push_back(vector<int>{start_p, end_p});
                start_p = intervals[i][0];
                end_p = intervals[i][1];
            }else{
                end_p = max(end_p, intervals[i][1]);
            }
        }
        ans.push_back(vector<int>{start_p, end_p});
        return ans;
    }
};