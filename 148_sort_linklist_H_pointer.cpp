/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
private:
ListNode *merge(ListNode*l1, ListNode* l2){
    auto tmp = new ListNode(0), head = tmp;
    while(l1 && l2){
        if(l1->val < l2->val){
            tmp->next = l1;
            l1 = l1->next;
        } else{
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    tmp->next = l1 ? l1 : l2;
    auto ans = head->next;
    delete head;
    head = NULL;
    return ans;
}
ListNode *dfs(ListNode* left){
    if(left == NULL || left->next == NULL) return left;
    auto fast = left, slow = left;
    // find the mid point using fast slow pointer
    while(fast && fast->next){
        fast = fast->next->next;
        if(fast && fast->next)  slow = slow->next;
    }
    auto mid = slow->next;
    slow->next = NULL;
    auto l1 = dfs(left);
    auto l2 = dfs(mid);
    
    auto tmp = merge(l1, l2);

    return tmp;
}
public:
    ListNode* sortList(ListNode* head) {
        return dfs(head);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
private:
ListNode *merge(ListNode*l1, ListNode* l2){
    auto tmp = new ListNode(0), head = tmp;
    while(l1 && l2){
        if(l1->val < l2->val){
            tmp->next = l1;
            l1 = l1->next;
        } else{
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    tmp->next = l1 ? l1 : l2;
    auto ans = head->next;
    delete head;
    head = NULL;
    return ans;
}
    
ListNode* cut(ListNode*head, int n){
    while(--n && head){ // take n
        head = head->next;
    }
    if(!head) return head;
    auto ans = head->next;
    head->next = NULL;   
    return ans;
}
public:
    ListNode* sortList(ListNode* head) {
        int size = 0;
        auto tmp = head;
        while(tmp){
            size ++;
            tmp = tmp->next;
        }
        auto new_head = new ListNode(0);
        new_head->next = head;
        for(int i = 1; i < size; i <<= 1){
            auto now = new_head->next;
            auto prev = new_head;
            while(now){
                auto l1 = now;
                auto l2 = cut(now, i);
                now = cut(l2, i);
                prev->next = merge(l1, l2);
                while(prev->next){
                    prev = prev->next;
                }
            }
        }
        auto ans = new_head->next;
        delete new_head;
        new_head = NULL;
        return ans;
    }
};