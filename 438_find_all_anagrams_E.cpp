class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return vector<int>();
        vector<int> f(128);
        vector<int>ans;
        int now = 0;
        for(auto i: p){
            if(f[i] == 0) now ++;
            f[i] ++;
        }
        int i = 0;
        for(; i + 1 < p.size(); i++){
            f[s[i]] --;
            if(f[s[i]] == 0) now --;
            else if(f[s[i]] == -1) now ++;
        }
        for(; i < s.size(); i++ ){
            f[s[i]] --;
            if(f[s[i]] == 0) now --;
            else if(f[s[i]] == -1) now ++;
            int start = i + 1 - p.size();
            if(now == 0) ans.push_back(start);
            f[s[start]] ++;
            if(f[s[start]] == 0) now --;
            else if(f[s[start]] == 1) now ++;
        }
        return ans;
    }
    
};