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
    void split (ListNode* root, ListNode** fir, ListNode** sec){
        ListNode*fast = root->next, *slow = root;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }
        *fir = root;
        *sec = slow->next;
        slow->next = nullptr;
    }
    ListNode* merge(ListNode* fir, ListNode* sec){
        if(!fir)
            return sec;
        if(!sec)
            return fir;
        ListNode* res;
        if(fir->val <= sec->val){
            res = fir;
            res->next = merge(fir->next, sec);
        }
        else{
            res = sec;
            res->next = merge(fir, sec->next);
        }
        return res;
    }
    void MERGESORT(ListNode ** head){
        if(!(*head) || !(*head)->next)
            return;
        ListNode *fir,*sec;
        split(*head, &fir, &sec);
        MERGESORT(&fir);
        MERGESORT(&sec);
        *head = merge(fir, sec);
    }
    ListNode* sortList(ListNode* head) {
        MERGESORT(&head);
        return head;
    }
};