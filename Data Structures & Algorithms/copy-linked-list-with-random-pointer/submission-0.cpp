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
        Node* res = new Node(-1);
        Node* dummy = res;
        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        while(curr != nullptr)
        {
            res->next = new Node(curr->val);
            mp[curr] = res->next;
            res = res->next;
            curr = curr->next;
        }

        Node* c = head;
        Node* r = dummy->next;
        while(c != nullptr)
        {
            r->random = mp[c->random];
            r = r->next;
            c = c->next;
        }

        return dummy->next;
    }
};
