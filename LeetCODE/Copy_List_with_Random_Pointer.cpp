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
    Node* copyRandomList(Node* head) {
        if(!head )
            return head;
        Node* curr = head;
        while(curr){
            Node* store = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = store;
            curr = store;
        }
        curr = head;
        while(curr){
            if(curr->next)
                curr->next->random = curr->random ? curr->random->next : curr->random;
            curr = curr->next ? curr->next->next : curr->next;
        }
        Node* res = head->next;
        Node* temp = res;
        curr = head;
        while(curr && temp){
            curr->next = curr->next ? curr->next->next : curr->next;
            temp->next = temp->next ? temp->next->next : temp->next;
            curr = curr->next;
            temp = temp->next;
        }
        return res;
    }
};