/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sz1 = 0,sz2 = 0;
        ListNode *temp = headA;
        while(temp){
            sz1++;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            sz2++;
            temp = temp->next;
        }
        temp = headA;
        ListNode *temp2 = headB;
        //cout<<sz1<<' '<<sz2<<endl;
        while(sz1>sz2){
            temp = temp->next;
            sz1--;
        }
        while(sz1<sz2){
            temp2 = temp2->next;
            sz2--;
        }
        //cout<<temp->val<<' '<<temp2->val<<endl;
        while(temp && temp2){
            if(temp==temp2)
                break;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return temp;
    }
};