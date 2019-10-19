class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ans = nums[0];
        while(l <= r){
            ans = min(nums[l], ans);
            if(nums[l] == nums[r]) {
                l ++; r--;
            }else break;
        }
        if(l > r) return ans;
        
        int last_element = nums[r];
        int split_idx = l - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > last_element) {
                split_idx = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        
        return min(ans, nums[split_idx+1]);
    }
}; 