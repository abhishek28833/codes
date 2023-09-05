/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int check(Node* head,Node* ptr){
        int cnt = 0;
        while(head!=ptr){
            head = head->next;
            cnt++;
        }
        return cnt;
    }

    Node* ran(Node* head,int cnt){
        while(cnt!=0 && head){
            head = head->next;
            cnt--;
        }
        return head;
    }


    Node* allocate(int data){
        Node* nn = new Node(data);
        nn->val = data;
        nn->next = NULL;
        nn->random = NULL;
        return nn;
    }

    Node* copyRandomList(Node* head) {
        Node* start = head;
        Node* ahead = NULL;
        Node* curr = NULL;
        while(start){
            int data = start->val;
            Node* nn = allocate(data);
            if(ahead==NULL){
                ahead = nn;
                curr = ahead;
            }
            else{
                curr->next = nn;
                curr = curr->next;
            }
            start = start->next;
        }
        start = head;
        curr = ahead;
        while(start){
            int cnt = check(head,start->random);
            Node* nn = ran(ahead,cnt);
            curr->random = nn;
            curr = curr->next;
            start = start->next;
        }
        return ahead;
    }
};