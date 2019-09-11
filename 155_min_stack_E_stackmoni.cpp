class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    stack<int> idx_stk;
    MinStack() {
        return;
    }
    
    void push(int x) {
        vec.push_back(x);
        if(idx_stk.empty() || vec[idx_stk.top()-1] > x) idx_stk.push(vec.size());
    }
    
    void pop() {
        if(idx_stk.top() == vec.size()) {
            idx_stk.pop();
        }
        vec.pop_back();
    }
    
    int top() {
        return *(vec.end() - 1);    
    }
    
    int getMin() {
        return vec[idx_stk.top() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */