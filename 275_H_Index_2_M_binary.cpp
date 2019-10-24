class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int n = citations.size();
        int ans = 0;
        int l = 1, r = citations.size();
        while(l <= r){
            int mid = (l + r) >> 1;
            int i = n - mid;
            if(citations[i] >= mid){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        return ans;
    }
};