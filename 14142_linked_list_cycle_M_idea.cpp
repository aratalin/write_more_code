/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1. 用hash做
class Solution {
public:
    typedef long long ll;
    bool hasCycle(ListNode *head) {
        unordered_set<ll>f;
        bool ans = true;
        auto now = head;
        while(now){
            if(f.count(ll(now))) return true;
            f.insert(ll(now));
            now = now->next;
        }
        return false;
    }
};

// 2. 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head, slow = head;
        bool start = true;
        while(fast && slow){
            if(!start && fast == slow) return true;
            
            fast = fast->next;
            if(!fast) return false;
            fast = fast->next;
            if(!fast) return false;
            slow = slow->next;
            start = false;
        }
        return false;
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
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        auto fast = head, slow = head;
        bool start = true;
        while(fast && slow){
            if(!start && fast == slow){break;};
            
            fast = fast->next;
            if(!fast) return NULL;
            fast = fast->next;
            if(!fast) return NULL;
            slow = slow->next;
            start = false;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};