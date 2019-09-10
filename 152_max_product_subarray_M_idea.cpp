class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size()) return 0;
        int min_ans = nums[0], max_ans = nums[0];
        int min_now = nums[0], max_now = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0){
                min_now = max_now = 0;
            }else if(nums[i] > 0){
                min_now = min(nums[i], min_now * nums[i]);
                max_now = max(nums[i], max_now * nums[i]);
            }else{
                int tmp = min(nums[i], max_now * nums[i]);
                max_now = max(nums[i], min_now * nums[i]);
                min_now = tmp;
            }
            min_ans = min(min_ans, min_now);
            max_ans = max(max_ans, max_now);
           // cout << max_ans<<" " << min_ans << " " <<min_now << " " << max_now<<endl;
        }
        
        return max_ans;
    }
};