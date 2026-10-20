class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head= new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* n)
    {
        Node* t = head->next;
        head->next = n;
        n->prev = head;

        t->prev=n;
        n->next=t;
    }

    void remove(Node* n)
    {
        Node* back = n->prev;
        Node* front = n->next;

        back->next = front;
        front->prev = back;
    }
    
    int get(int key) {
        auto it = mp.find(key);

        if(it == mp.end())
            return -1;

        Node* n = it->second;
        remove(n);
        insertAfterHead(n);
        return n->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end())
        {
            Node* n = it->second;
            n->val = value;
            remove(n);
            insertAfterHead(n);
            return;
        }

        if(cap == 0)
        {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
            cap++;
        }

        Node* n = new Node(key, value);
        insertAfterHead(n);
        mp[key] = n;
        cap--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */