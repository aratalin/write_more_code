class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int now = 1;
        int ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(ans == nums[i]) now ++;
            else{
                now --;
                if(now <= 0) {
                    ans = nums[i];
                    now = 1;
                }
            }
            if(now > nums.size() - i - 1 ) break;
        }
        return ans;
    }
};