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
    ListNode* reverseList(ListNode *curr)
    {
        if(!curr || !curr->next)
            return curr;
        ListNode *head = reverseList(curr->next);
        curr->next->next = curr;
        curr->next = NULL;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast)
            slow = slow->next;
        slow = reverseList(slow);
        ListNode* temp = head;
        fast = slow;
        while(fast){
            if(fast->val!=temp->val)
                return false;
            fast = fast->next;
            temp = temp->next;
        }
        slow = reverseList(slow);
        return true;
    }
};