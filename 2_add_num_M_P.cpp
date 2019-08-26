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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *start,*pre;
        pre = l1;
        start = l1;
        int add_flag = 0;
        while(l1 && l2){
            l1->val += (l2->val + add_flag);
            add_flag = l1->val / 10;
            l1->val %= 10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
            
        }
        while(l1){
                l1->val += add_flag;
                add_flag = l1->val / 10;
                l1->val %= 10;
                pre = l1;
                l1 = l1->next;
        }
        while(l2){
                l2->val += add_flag;
                add_flag = l2->val / 10;
                l2->val %= 10;
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
        }
        if (add_flag){
            pre->next = new ListNode(1);
        }
        return start;
    }
};