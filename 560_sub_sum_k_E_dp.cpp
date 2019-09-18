class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>f;
        int ans = 0;
        int pre = 0;
        
        f[0] = 1;
        for(auto i: nums){
            pre += i;
            int target = pre - k;
            if(f.count(target)) ans += f[target];
            if(f.count(pre) == 0) f[pre] = 0;
            f[pre] += 1;
        }
        return ans;
    }
};