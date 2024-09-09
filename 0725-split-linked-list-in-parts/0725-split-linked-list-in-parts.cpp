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
    int count(ListNode* st){
        ListNode* head = st;
        int cnt = 0;
        while(head!=NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> arr;
        int cnt = count(head);
        int val = cnt/k;
        int rem = cnt%k;
        // cout<<cnt;
        ListNode* temp=head,*curr=head;
        while(k--){
            temp = curr;
            arr.push_back(curr);
            int c = val;
            while(c--){
                temp = curr;
                curr = curr->next;
            }
            if(rem>0){
                temp = curr;
                if(curr)
                curr = curr->next;
                rem--;
            }
            if(temp)
            temp->next = NULL;

        }
        return arr;
    }
};