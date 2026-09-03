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
    void clone(Node* n, Node* o, unordered_map<Node*,Node*> &mp)
    {
        for(auto nei : o->neighbors)
        {
            if(mp.find(nei) == mp.end())
            {
                Node* node = new Node(nei->val);
                n->neighbors.push_back(node);
                mp[nei]=node;
                clone(node, nei, mp);
            }
            else
            {
                n->neighbors.push_back(mp[nei]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        Node* root = new Node(node->val);
        unordered_map<Node*,Node*> mp; //old->new
        mp[node] = root;

        clone(root, node, mp);
        return root;
    }
};
