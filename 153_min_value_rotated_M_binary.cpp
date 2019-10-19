class Solution {
public:
    int findMin(vector<int>& nums) {
        int split_idx = -1; 
        int l = 0, r = nums.size() - 1;
        int last_element = nums[r];
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > last_element) {
                split_idx = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        return nums[split_idx + 1]; 
    }
};