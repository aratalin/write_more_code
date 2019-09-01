class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 2 < nums.size(); i++){
            if (i && nums[i] == nums[i-1]) continue;
            if(nums[i] > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                }
                else if(nums[i] + nums[l] + nums[r] > 0) r--;
                else l++;
            }

        }
        return ans;
    }
    
};