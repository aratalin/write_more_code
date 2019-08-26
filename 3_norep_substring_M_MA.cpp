class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int>vis_tag;
        int ans = 0;
        int now = 0;
        int l = 0, r = 0;
        while(r < s.length()){
            if(vis_tag.find(s[r]) == vis_tag.end()){
                now ++;
                if (now > ans) ans = now;
                vis_tag.insert(s[r]);
            }else{
                while(s[l] != s[r]) {
                    vis_tag.erase(s[l]);
                    l++;
                    now--;
                }
                l ++;
            }
            r++;
        }
        return ans;
    }
};