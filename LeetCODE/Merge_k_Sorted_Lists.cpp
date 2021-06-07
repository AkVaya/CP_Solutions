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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* i : lists)
            if(i)
                pq.push(i);
        while(pq.size()){
            ListNode* curr = pq.top();
            pq.pop();
            temp->next = curr;
            temp = curr;
            if(curr->next)
                pq.push(curr->next);
        }
        return res->next;
    }
};