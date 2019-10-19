class Solution {
    
public:
    bool binarySearch(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] == target) return true;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            if(nums[l] == target || nums[r] == target) return true; 
            if(nums[l] == nums[r]) {
                l++; r--;
            }else break;
        }
        if(l > r) return false;
        int a_l = l, a_r = r, splitPoint = l; 
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[a_r]){  // high light this line
                l = mid + 1;
                splitPoint = mid;
            } else r = mid - 1;
        }
        if(nums[a_r] >= target) return binarySearch(nums, target, splitPoint + 1, a_r);
        return binarySearch(nums, target, a_l, splitPoint);
        
    }
};