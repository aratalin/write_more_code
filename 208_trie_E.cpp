class Trie {
public:
    struct TrieNode{
        bool end;
        map<char, TrieNode*> f;
        TrieNode(): end(false){};
    };
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto now = this->root;
        for(auto ch : word){
            if(now->f.find(ch) == now->f.end()) now->f[ch] = new TrieNode();
            now = now->f[ch];
        }
        now->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto now = this->root;
        for(auto ch : word){
            if(now->f.count(ch) == 0) return false;
            now = now->f[ch];
        }
        return now->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto now = this->root;
        for(auto ch : prefix){
            if(now->f.count(ch) == 0) return false;
            now = now->f[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */