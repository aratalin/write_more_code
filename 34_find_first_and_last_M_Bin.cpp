class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto pos1 = lower_bound(nums.begin(), nums.end(), target);
        if(pos1 == nums.end() || (*pos1 != target)) return vector<int>{-1,-1};
        auto pos2 = upper_bound(nums.begin(), nums.end(), target);
        return vector<int>{pos1-nums.begin(), pos2-nums.begin() - 1};
    }
};


class Solution {
private:
    int find_target(vector<int>&nums, int target, bool lower){
        if(nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] == target){
                ans = mid;
                if(lower) r = mid - 1;
                else l = mid + 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }else r = mid - 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1 = -1, ans2 = -1;
        ans1 = find_target(nums, target, true);
        if(ans1 == -1) return vector<int>{-1, -1};
        ans2 = find_target(nums, target, false);
        return vector<int>{ans1, ans2};
    }
};