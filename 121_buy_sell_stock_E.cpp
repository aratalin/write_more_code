class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int pre_min = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > pre_min && (prices[i] - pre_min) > ans){
                ans = prices[i] - pre_min;
            }
            pre_min = min(pre_min, prices[i]);
        }
        return ans;
    }
};