class Solution {
private:
unordered_set<int> f;
public:
    int longestConsecutive(vector<int>& nums) {
        for(auto i: nums) f.insert(i);
        int ans = 0;
        for(auto i: f){
            if(f.count(i-1)) continue;
            
            int j = i + 1;
            while(f.count(j)) j++;
            ans = max(ans, j - i);
        }
        return ans;
    }
};