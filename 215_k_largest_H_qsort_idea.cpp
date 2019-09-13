class Solution {
public:
    int partition(vector<int>& nums, int s, int e){
        if(s == e) return s;
        int now = nums[s];
        while(s < e){
            while(s < e && nums[e] <= now) --e;
            nums[s] = nums[e];
            while(s < e && nums[s] >= now) ++s;
            nums[e] = nums[s];
        }
        nums[s] = now;
        return s;
    }

    
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0, e = nums.size() - 1;
        while(s<= e){
            int pivot_pos = partition(nums, s, e);
            if(pivot_pos + 1 == k) return nums[pivot_pos];
            if(pivot_pos >= k) e = pivot_pos - 1;
            else s = pivot_pos + 1;
        }
        return 0;
    }
};