class Solution {
private:
    map<char, int> f;
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0 || s.size() < t.size()) return "";
        int n = s.size(), m = t.size();
        int meet = 0;
        for(int i = 0; i < m; i++){
            if(f.find(t[i]) == f.end()) {
                f[t[i]] = 0;
                meet ++;
            }
            f[t[i]] = f[t[i]] + 1;
        }
        int l = 0, r = 0;
        int start_pos = 0;
        int min_length = INT_MAX;
        while(l < n){
            
            if(meet == 0){
                if(r - l < min_length){
                    min_length = r - l;
                    start_pos = l;
                } 
                if(f.find(s[l]) == f.end()){l++; continue;}
                f[s[l]] ++;
                if(f[s[l]] == 1) meet++;
                l++;
            } // move left
            else if(r < n){
                if(f.find(s[r]) == f.end()) {
                    r ++;
                    continue;
                }
                f[s[r]] --;
                if(f[s[r]] == 0){
                    meet --;
                }
                r ++;
            } // move right;
            else{
                break;
            }
        }
        if(min_length > n) return "";
        return s.substr(start_pos, min_length) ;
    }
};