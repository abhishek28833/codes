/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        queue<ListNode*> small;
        queue<ListNode*> big;
        while(head != NULL){
            if(head->val < x) small.push(head);
            else big.push(head);
            head = head->next;
        }
        ListNode* start = NULL;
        if(small.size()==0){
            start = big.front();
            big.pop();
        }
        else{
            start = small.front();
            small.pop();
        }
        ListNode* curr = start;
        while(!small.empty()){
            curr->next = small.front();
            curr = curr->next;
            small.pop();
        }
        while(!big.empty()){
            curr->next = big.front();
            curr = curr->next;
            big.pop();
        }
        curr->next = NULL;
        return start;
    }
};