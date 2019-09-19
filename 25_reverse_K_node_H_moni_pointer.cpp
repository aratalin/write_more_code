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
    void reverse(ListNode* head, ListNode* pre){
        auto tmp = pre;
        while(head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto tmp_head = new ListNode(0);
        auto tail = tmp_head;
        while(true){
            auto left = head;
            int now = k;
            auto pre_head = tail;
            while(now && head){
                now --;
                pre_head = head;
                head = head->next;
            }
            if(now == k) break;
            if(now != 0){
                tail->next = left;
                break;
            }
            pre_head->next = NULL;
            reverse(left, NULL);
            auto gg = pre_head;
            
            tail->next = pre_head;
            tail = left;
            
        }   
        return tmp_head->next;
        
    }
};