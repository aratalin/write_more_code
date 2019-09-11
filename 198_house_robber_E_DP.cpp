class Solution {
public:
    int rob(vector<int>& nums) {
        int vmax = 0, nvmax = 0;
        for(int i = 0; i < nums.size(); i++){
            int steal = nvmax + nums[i];
            nvmax = max(nvmax, vmax);
            vmax = steal;
        }
        
        return max(vmax, nvmax);
    }
};