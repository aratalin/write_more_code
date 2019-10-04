class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        
        vector<int> f(26, 0);
        for(auto c: s1){
            f[c - 'a'] ++;
        }
        for(auto c: s2){
            f[c - 'a'] --;
        }
        for(int i = 0; i < 26; i++) {
            if (f[i]) return false;
        }
        
        for(int i = 1; i < s1.size(); i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i)) 
              ) return true;
            if(isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)) 
              ) return true;
        }
        return false;
    }
};