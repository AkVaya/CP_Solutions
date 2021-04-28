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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode *prev = NULL,*curr = head,*nxt = head->next, *start = head;
        int cnt = 1;
        while(nxt && cnt<k){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            cnt++;
        }
        curr->next = prev;
        if(cnt<k){
            ListNode * revStart = curr;
            nxt = prev;
            prev = NULL;
            //cout<<curr->val<<' '<<nxt->val<<endl;
            while(cnt>1){
                cnt--;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
            curr->next = prev;
            //curr->next = curr;
        }
        else{
            start->next = reverseKGroup(nxt,k);
        }
        
        return curr;
    }
};