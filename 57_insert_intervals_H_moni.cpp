class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();
        for(; i < n; i++){
            if(intervals[i][1] >= newInterval[0]) {
                break;
            }
        }
        if(i == n){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(intervals[i][0] > newInterval[1]){
            // not cover
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }
        int left = newInterval[0], right = newInterval[1];
        int newpos = i;
        while(i < n){
            if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1]){
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            }else{
                break;
            }
            i++;
        }
        intervals[newpos] = vector<int>{left, right};
        while(i < n){
            newpos ++;
            intervals[newpos] = intervals[i];
            i++;
        }
        while(newpos + 1< n){
            intervals.pop_back();
            newpos ++;
        }
        return intervals;
    }
};