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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        auto last = head;
        int len = 1;
        while(last && last->next) {
            last = last->next;
            len ++;
        }
        last->next = head;
        int move = (len - k % len + len) % len;
        auto pre = last;
        while(move){
            pre = head;
            head = head->next;
            move--;
        }
        pre->next = NULL;
        return head;
    }
};