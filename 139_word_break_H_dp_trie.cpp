class Solution {

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> vis(s.size() + 1, false);
        unordered_set<string> f;
        for(auto word : wordDict){
            f.insert(word);
        }
        vis[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(!vis[j]) continue;
                if(f.count(s.substr(j, i - j))){
                    vis[i] = true;
                    break;
                }
            }
        }
        return vis[s.size()];
    }
};


class Solution {

public:
    struct TrieNode{
        bool flag;
        map<char, TrieNode*> next;
        TrieNode(): flag(false){}
    };
    TrieNode *root;
    vector<int> vis;
    bool search_trie(string &s, int begin, int end){
        if(begin == end) return true;
        if(vis[begin] != -1) return vis[begin];
        TrieNode* now = root;
        for(int i = begin; i < end; i++){
            if(now->next.count(s[i]) == 0){
                break;
            }
            now = now->next[s[i]];
            if(now->flag && search_trie(s, i + 1, end)){
                vis[begin] = 1;
                return true;
            }
        }
        vis[begin] = 0;
        return false;
    }
    void struct_trie(vector<string>& wordDict){
        root = new TrieNode();
        for(auto word: wordDict){
            TrieNode* now = root;
            for(auto c: word){
                if(now->next.find(c) == now->next.end()){
                    now->next[c] = new TrieNode();
                }
                now = now->next[c];
            }
            now->flag = true;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        struct_trie(wordDict);
        vis = vector<int>(s.size(), -1);
        return search_trie(s, 0, s.size());
    }
};