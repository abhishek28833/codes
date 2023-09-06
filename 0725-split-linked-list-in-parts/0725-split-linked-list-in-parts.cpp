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
    int count(ListNode* head){
        int cnt =0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = count(head);
        vector<ListNode*> ans;
        int div = cnt/k;
        int mod = cnt % k;
        if(cnt>k){
            while(head != NULL){
                ans.push_back(head);
                for(int i=0;i<div-1;i++){
                    head = head->next;
                }
                if(mod != 0){
                    head = head->next;
                    mod--;
                }
                ListNode* save = head;
                if(head != NULL){
                    head = head->next;
                    save->next = NULL;
                }
            }
        }
        else{
            while(head != NULL){
                ans.push_back(head);
                ListNode* save = head;
                head = head->next;
                save->next = NULL;
            }
            if(cnt<k){
                int a = k-cnt;
                for(int i=0;i<a;i++){
                    ans.push_back(NULL);
                }
            }
        }
        return ans;
    }
};