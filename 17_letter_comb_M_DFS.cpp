class Solution {
private:
    map<char, string> f;
    void init(){
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";
    }
    void dfs(string digits, int now, string &now_string, vector<string> &ans){
        if (now == digits.size()){
            ans.push_back(now_string);
            return;
        }
        string char_list = f[digits[now]];
        for (int i = 0; i < char_list.size(); i++){
            now_string[now] = char_list[i];
            dfs(digits, now+ 1, now_string, ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if (digits.size() == 0) return ans;
        this->init();
        string now_string(digits.size() + 1, '\0');
        this->dfs(digits, 0, now_string, ans);
        return ans;
    }
};