class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpin = INT_MIN, dpout = INT_MIN, dpfre = 0;
        for(auto x : prices){
            int newin = dpfre - x;
            int newout = dpin + x;
            int newfre = dpout;
            dpin = max(dpin, newin);
            dpout = max(dpout, newout);
            dpfre = max(dpfre, newfre);
        }
        return max(dpin, max(dpout, dpfre));
    }
};
