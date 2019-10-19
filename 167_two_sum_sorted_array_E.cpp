class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 0) return vector<int>{-1, -1};
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            int tmp = numbers[l] + numbers[r];
            if(tmp == target) return vector<int>{l + 1, r + 1};
            if(tmp > target) r --;
            else l ++;
        }
        return vector<int>{-1, -1};
    }
};