class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return;
        int n = nums.size();
        int pos_0 = 0, pos_2 = nums.size() - 1, now;

        now = pos_0;

        while(now <= pos_2){
            if(nums[now] == 0){
                swap(nums[now], nums[pos_0]);
                pos_0 ++; now ++;
            }else if(nums[now] == 2){
                swap(nums[now], nums[pos_2]);
                pos_2 --;
            }else now ++;
        }

    }
};