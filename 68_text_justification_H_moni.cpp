class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int l = 0;
        while(l < words.size()){
            int r = l, now = 0;
            while(r < words.size() && now + words[r].size() + r - l <= maxWidth) {
                now += words[r].size();
                r++;
            }
            if (r == l + 1){
                string tmp = words[l] + string(maxWidth - words[l].size(), ' ');
                ans.push_back(tmp);
            }else if (r == words.size()){
                string tmp = "";
                for(int i = l; i < r; i++){
                    tmp += words[i];
                    if(i + 1 != r) tmp += " ";
                }
                tmp += string(maxWidth - tmp.size(), ' ');
                ans.push_back(tmp);
            }
            else{
                int spaceNum = maxWidth - now;
                int moreSpace = spaceNum % ( r - l - 1);
                int baseSpace = spaceNum / (r - l - 1);
                string tmp = "";
                for(int i = 0; i + l + 1< r; i++){
                    tmp = tmp + words[i + l] + string(baseSpace + (moreSpace > i ? 1 : 0 ), ' ');
                }
                tmp += words[r-1];
                ans.push_back(tmp);
            }
            l = r;
        }
        
        return ans;
    }
};