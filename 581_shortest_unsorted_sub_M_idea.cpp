class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int l = 1, r = nums.size() - 2;
        int minv = INT_MAX, maxv = INT_MIN;
        while(l < nums.size()){
            if(nums[l] < nums[l-1]) break;
            l++;
        }
        while(r >= 0){
            if(nums[r] > nums[r+1]) break;
            r--;
        }
        if(l == nums.size()) return 0;
        while(l < nums.size()) {
            minv = min(minv, nums[l]);
            l++;
        }
        while(r >= 0) {
            maxv = max(maxv, nums[r]);
            r--;
        }
        
        l = 0; 
        r = nums.size() - 1;
        while(l < nums.size()){
            if(nums[l] > minv) break; 
            l++;
        }
        while(r >= 0){
            if(nums[r] < maxv) break;
            r--;
        }
        return r - l + 1;
    }
};