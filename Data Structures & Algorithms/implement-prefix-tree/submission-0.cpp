class PrefixTree {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* next[26];

        TrieNode(){
            isEnd = false;
            for(int i=0; i<26; i++)
            {
                next[i] = nullptr;
            }
        }
    };

    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->next[c-'a'] == nullptr)
            {
                curr->next[c-'a'] = new TrieNode();
            }
             curr = curr->next[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(!curr->next[c-'a'])
                return false;
            
            curr = curr->next[c-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix)
        {
            if(!curr->next[c-'a'])
                return false;
            
            curr = curr->next[c-'a'];
        }
        return true;
    }
};
