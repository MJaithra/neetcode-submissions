class LRUCache {
public:
    class Node {
        public :
            int key;
            int value;
            Node* prev;
            Node* next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    void remove(Node* n)
    {
        Node* bef = n->prev;
        Node* aft = n->next;

        bef->next = aft;
        aft->prev = bef;
    }

    void insertAfterHead(Node* n)
    {
        Node* after = head->next;
        n->next = after;
        n->prev = head;

        head->next = n;
        after->prev = n;
    }

    int cap;
    unordered_map<int, Node*> mp;
    Node* head; Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

        //mp.reserve(capacity);
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        Node* n = mp[key];
        remove(n);
        insertAfterHead(n);

        return n->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            Node* n = mp[key];
            n->value = value;
            remove(n);
            insertAfterHead(n);
            return;
        }

        if(mp.size() == cap)
        {
            int lruKey = tail->prev->key;
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lruKey);
            delete lru;
        }
        Node* n = new Node(key, value);
        insertAfterHead(n);
        mp[key] = n;
    }
};
