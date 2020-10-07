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
    ListNode* once(ListNode *curr){
        ListNode* temp = curr;
        while(temp->next->next){
            temp=temp->next;
        }
        temp->next->next = curr;
        curr = temp->next;
        temp->next = nullptr;
        return curr;
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *temp = head;
        int cnt = 0;
        while(temp){
            ++cnt;
            temp = temp->next;
        }
        k%=cnt;
        while(k--){
            head = once(head);
        }
        return head;
    }
};