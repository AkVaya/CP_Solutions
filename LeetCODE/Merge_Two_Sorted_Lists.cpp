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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(),* temp;
        temp = res;
        while(l1 || l2){
            while(l1!=nullptr && (l2==nullptr ||l1->val<=l2->val)){
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1=l1->next;
            }
            while(l2!=nullptr && (l1==nullptr ||l2->val<=l1->val)){
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2=l2->next;
            }
        }
        return res->next;
    }
};