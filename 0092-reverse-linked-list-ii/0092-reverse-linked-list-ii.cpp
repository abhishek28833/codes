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
    int countnode(ListNode* head){
        int cnt =0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* insertbeg(ListNode* head,ListNode* add){
        ListNode* curr = NULL;
        while(head != add){
            if(curr == NULL){
                curr = head;
                head=head->next;
                curr->next = NULL;
                
            }
            else{
                ListNode* temp = head;
                head = head->next;
                temp->next = curr;
                curr=temp;
            }
        }
        ListNode* temp = head;
        temp->next = curr;
        curr=temp;

        return curr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        int x = countnode(head);
        int cnt =1;
        while(head != NULL && cnt < left-1){
            cnt++;
            head = head->next;
        }
        ListNode* a= head;
        while(head != NULL && cnt < right){
            cnt++;
            head = head->next;
        }
        ListNode* b= head->next;
        if(left == right)
        return curr;
        ListNode* temp;
        if(left == 1){
            temp = insertbeg(a,head);
            
            if(right != x){
                ListNode* p = temp;
                while(p->next != NULL)
                p = p->next;
                p->next = b;
            }
            return temp;
        }
        else
        temp = insertbeg(a->next,head);
        a->next = temp;
        while(temp->next != NULL)
        temp = temp->next;
        temp->next = b;
        return curr;
        


    }
};