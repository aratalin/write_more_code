class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        if(n == 1) return heights[0];
        
        stack<int> st;
        vector<int> l(heights.size());
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(st.empty()) l[i] = 0;
            else l[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int ans = 0 ;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            int r;
            if(st.empty()) r = n - 1;
            else r = st.top() - 1;
            ans = max((r - l[i] + 1) * heights[i], ans);
            st.push(i);
        }
        return ans;
    }
};