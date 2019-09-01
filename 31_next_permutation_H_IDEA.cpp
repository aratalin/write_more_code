class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        int start_move = nums.size() - 2;
        while(start_move>=0){
            if(nums[start_move] < nums[start_move + 1]) break;
            start_move --;
        }
        if(start_move < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int end_move = start_move + 1;
        while(end_move < nums.size()){
            if(nums[end_move] <= nums[start_move]) break; //here
            end_move ++;
        }
        swap(nums[end_move - 1], nums[start_move]);
        reverse(nums.begin() + start_move + 1, nums.end());

    }
};