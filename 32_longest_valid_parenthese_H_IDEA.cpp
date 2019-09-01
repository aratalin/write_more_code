class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '(') stk.push(i);
            else{
                int top_idx = stk.top();
                if(top_idx!= -1 && s[top_idx] == '('){
                    stk.pop();
                    ans = max(i - stk.top(), ans);
                }else{
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};