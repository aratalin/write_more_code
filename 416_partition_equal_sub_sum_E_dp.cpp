class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums) sum += i;
        if(sum & 1) return false;
        int ans = sum >> 1;
        vector<int> dp( ans + 1, 0);
        dp[0] = 1;
        
        //sort(nums.begin(), nums.end());
        for(auto i: nums){
            for(int j = ans; j >= i; j--){
                dp[j] |= dp[j - i];
            }
        }
        return dp[ans];
    }
};