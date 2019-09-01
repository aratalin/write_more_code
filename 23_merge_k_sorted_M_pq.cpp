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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; // 是否把a往后放
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = new ListNode(0), *head = ans;
        priority_queue<ListNode*, vector<ListNode*>, cmp > pq;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            ListNode *now = pq.top(); pq.pop();
            head->next = now;
            head = head->next;
            if(now->next != NULL) {
                pq.push(now->next);
            }
        }
        return ans->next;
    }
};