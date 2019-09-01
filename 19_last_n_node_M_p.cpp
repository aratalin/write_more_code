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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *next_n=head, *now = head;
        while(n --){
            next_n = next_n->next;
        }
        if (next_n == NULL){
            return head->next;
        }
        while(true){
            next_n = next_n->next;
            if(next_n == NULL){
                break;
            }
            now = now->next;
        }
        ListNode *tmp = now->next;
        now->next = now->next->next;
        delete tmp;
        return head;
    }
};