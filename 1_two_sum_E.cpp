class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>f;
        vector<int>ans = vector<int>(2);
        for(int i = 0; i < nums.size(); i++){
            if(f.find(target - nums[i]) != f.end()) {

                ans[0] = f[target-nums[i]];
                ans[1] = i;
                return ans;
            }
            f[nums[i]] = i;
        }
        return ans;
        
    }
};