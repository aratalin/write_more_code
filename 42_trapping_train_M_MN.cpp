class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        vector<int> f(height.size());
        f[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            f[i] = max(f[i - 1], height[i]);
        }
        int ans = 0;
        int right_f = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            right_f = max(right_f, height[i]);
            ans += (min(right_f, f[i]) - height[i]);
        }
        return ans;
    }
};