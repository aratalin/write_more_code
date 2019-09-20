class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(words.size() == 0){
            return ans;
        }
        
        int word_len = words[0].size();
        int all_len = words.size() * word_len;
        unordered_map<string, int> f;
        int ned = 0;
        for(auto word: words) {
            if(f.count(word) == 0){
                ned += 1;
                f[word] = 0;
            } 
            f[word] += 1;
        }
        
        for(int j = 0; j < word_len; j++){
            int now = ned;
            int l = j, r = l;
            unordered_map<string, int> tmp;
            while(l + all_len <= s.size()){
                auto sub = s.substr(r, word_len);
                while(f.count(sub) && tmp[sub] < f[sub]){
                    tmp[sub] += 1;
                    r += word_len;
                    sub = s.substr(r, word_len);
                }
                if(r - l == all_len){
                    ans.push_back(l);
                    sub = s.substr(l, word_len);
                    tmp[sub] -= 1;
                    l += word_len;
                }else if(f.count(sub)){
                    sub = s.substr(l, word_len);
                    tmp[sub] -= 1;
                    l += word_len;
                }
                else{
                    r += word_len;
                    l = r;
                    tmp.clear();
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(words.size() == 0){
            return ans;
        }
        
        int word_len = words[0].size();
        int all_len = words.size() * word_len;
        unordered_map<string, int> f;
        int ned = 0;
        for(auto word: words) {
            if(f.count(word) == 0){
                ned += 1;
                f[word] = 0;
            } 
            f[word] += 1;
        }
        
        for(int j = 0; j < word_len; j++){
            int now = ned;
            int l = j;
            unordered_map<string, int> tmp;
            for(int i = j; i + word_len <= s.size(); i += word_len){
                auto now_word = s.substr(i, word_len);
                if(f.count(now_word) == 0){
                    tmp.clear();
                    l = i + word_len;
                    continue;
                }
                tmp[now_word] += 1;
                while(tmp[now_word] > f[now_word] && l <= i){
                    auto lw = s.substr(l, word_len);
                    tmp[lw] --;
                    l += word_len;
                }
                if(i - l + word_len == all_len) {
                    ans.push_back(l);
                    auto lw = s.substr(l, word_len);
                    tmp[lw] --;
                    l += word_len;
                }
            }
        }
        return ans;
    }
};

执行用时 :
32 ms
, 在所有 C++ 提交中击败了
97.71%
的用户
内存消耗 :
14.7 MB
, 在所有 C++ 提交中击败了
77.01%
的用户