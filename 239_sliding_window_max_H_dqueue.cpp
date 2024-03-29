class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        vector<int> ans;
        if(nums.size() ==0) return ans;
        for(int i = 0; i < k; i++){
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i = k; i < nums.size(); i ++){
            if(!q.empty() &&  i - q.front() == k) q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            ans.push_back(nums[q.front()]);   
        }
        
        return ans;
    }
};