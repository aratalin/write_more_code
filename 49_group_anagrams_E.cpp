class Solution {
private:
    unordered_map<string, int> f;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(f.find(tmp) == f.end()){
                ans.push_back(vector<string>());
                f[tmp] = ans.size() - 1;
            }
            ans[f[tmp]].push_back(s);
        }
        return ans;
    }
};