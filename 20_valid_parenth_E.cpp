class Solution {
private:
    bool is_match(char l, char r){
        if(l == '(' && r == ')') return true;
        if(l == '{' && r == '}') return true;
        if(l == '[' && r == ']') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s){
            if(!stk.empty() && is_match(stk.top(), c)){
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};