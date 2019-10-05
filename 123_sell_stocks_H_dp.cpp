class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN / 2, buy2 = INT_MIN / 3, sell1 = INT_MIN / 2, sell2 = INT_MIN / 3;
        int ans = 0;
        
        for(auto num : prices){
            sell2 = max(sell2, buy2+num);
            buy2 = max(buy2, sell1-num);
            sell1 = max(sell1, buy1+num);
            buy1 = max(buy1, -num);
            ans = max(ans, max(sell1, sell2));
        }
        return ans;
    }
};