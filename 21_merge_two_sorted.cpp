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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0), *head = ans;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2->val){
                ans->next = l1;
                l1 = l1->next;
            }else{
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        if(l1 != NULL){
            ans->next = l1;
        }
        else if(l2 != NULL){
            ans->next = l2;
        }
        return head->next;
        
    }
};