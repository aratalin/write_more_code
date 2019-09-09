class LRUCache {
private:
    struct BiNode{
        int val, key;
        BiNode* left, *right;
        BiNode(int _key, int _val):key(_key), val(_val), left(NULL), right(NULL){};
    };
    BiNode* head;
    BiNode* tail;
    unordered_map<int, BiNode*> f;
    int capacity;
public:
    
    LRUCache(int capacity) {
        head = new BiNode(0,0);
        tail = new BiNode(0,0);
        head->right = tail;
        tail->left = head;

        this->capacity = capacity;
    }

    void insert_tail(BiNode* node){
        node->left = tail->left;
        tail->left->right = node;
        tail->left = node;
        node->right = tail;
    }
    void remove_node(BiNode* node){
        auto tmp_r = node->right;
        auto tmp_l = node->left;
        tmp_l->right = tmp_r;
        tmp_r->left = tmp_l;
    }
    
    int get(int key) {
        if(f.count(key)) {
            remove_node(f[key]);
            insert_tail(f[key]);
            return f[key]->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(f.count(key)) {
            f[key]->val = value;
            remove_node(f[key]);
            insert_tail(f[key]);
        }else{
            if(f.size() == capacity){
                auto tmp = head->right;
                f.erase(tmp->key);
                remove_node(tmp);
                delete tmp;
                tmp = NULL;
            }
            auto node = new BiNode(key, value);
            f[key] = node;
            insert_tail(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */