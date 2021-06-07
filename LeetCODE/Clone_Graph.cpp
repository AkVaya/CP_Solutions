/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* res = nullptr;
        if(!node)
            return node;
        map<Node*, Node*> change;
        change[node] = new Node(node->val);
        queue<Node* > q;
        q.push(node);
        while(q.size()){
            Node* curr = q.front();
            q.pop();
            if(!res)
                res = change[curr];
            for(Node* i : curr->neighbors){
                if(!change.count(i)){
                    q.push(i);
                    change[i] = new Node(i->val);
                }
                change[curr]->neighbors.push_back(change[i]);
            }
        }
        return res;
        
    }
};