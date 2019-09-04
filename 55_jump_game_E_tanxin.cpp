class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return true;
        int far = 0;
        for(int i = 0; i <= far; i++){
            far = max(nums[i] + i, far);
            if(far >= nums.size()) break;
        }
        return far >= nums.size() - 1;
    }
};