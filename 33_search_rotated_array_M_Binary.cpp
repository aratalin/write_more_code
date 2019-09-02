class Solution {
private:
    int find_target(vector<int>&nums, int begin, int end, int target){
        int l = begin, r = end;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }else r = mid - 1;
        }
        return ans;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int len = nums.size();
        int l = 0, r = len - 1;
        int split_idx = -1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[len - 1]){
                split_idx = mid; 
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        ans = find_target(nums, 0, split_idx, target);
        if(ans == -1) ans = find_target(nums, split_idx + 1, nums.size() - 1, target);
        return ans;
        
    }
};