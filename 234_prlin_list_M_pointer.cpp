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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *left_head = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            left_head = slow;
            slow = slow->next;
        }
        auto cur = slow;
        if(fast) cur = cur->next;
        ListNode *pre = NULL;
        while(head){
            auto tmp = head->next;
            head->next = pre;
            if(head == left_head) break;
            pre = head;
            head = tmp;
        }
        while(left_head && cur){
            if(left_head->val != cur->val) return false;
            left_head = left_head->next;
            cur = cur->next;
        }
        return true;
    }
};