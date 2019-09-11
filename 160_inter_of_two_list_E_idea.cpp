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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headB || !headA) return NULL;
        auto tailB = headB;
        while(tailB->next){
            tailB = tailB->next;
        }
        
        tailB->next = headA;
        auto tmp = detectCycle(headB);
        tailB->next = NULL;
        return tmp;
        
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0, m = 0;
        auto tmpa = headA, tmpb = headB;
        auto headLong = headA, headShort=headB;
        while(tmpa) {
            n++; tmpa = tmpa->next;
        }
        while(tmpb){
            m++; tmpb = tmpb->next;
        }
        if(n < m) {
            swap(headLong, headShort);
            swap(n, m);
        }
        while(n > m) {
            n--;headLong = headLong->next;
        }
        
        while(headLong != headShort){
            headLong = headLong->next;
            headShort = headShort->next;
        }
        return headLong;
    }   
};