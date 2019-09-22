class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0) nums[i] = nums.size() + 1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) > nums.size()) continue;
            int idx = abs(nums[i]) - 1;
           
            nums[idx] = - abs(nums[idx]);
        }
        int ans = 0;
        for(; ans < nums.size(); ans++){
            if(nums[ans] > 0) {
                break;
            }
        }
        return ans + 1;
    }
};