class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ans(T.size(), 0);
        stack<int> pst;
        for(int i = 0; i < T.size(); i++){
            while(!pst.empty() && T[i] > T[pst.top()]){
                int now = pst.top(); pst.pop();
                ans[now] = i - now ;
            }
            pst.push(i);
        }
        
        return ans;
    }
};