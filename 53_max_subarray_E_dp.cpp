class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -2147483648;
        int pre = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(pre < 0){
                pre = nums[i];
            }else{
                pre = pre + nums[i];
            }
            ans = max(pre, ans);
        }
    return ans;
    }
    
};