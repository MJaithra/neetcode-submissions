class WordDictionary {
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
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(!curr->next[c-'a'])
            {
                curr->next[c-'a'] = new TrieNode();
            }

            curr = curr->next[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool backtrack(int ind, string &word, TrieNode* curr)
    {
        if(ind == word.length())
        {
            return curr->isEnd;
        }

        char c = word[ind];
        if(c != '.')
        {
            if(curr->next[c-'a'])
                return backtrack(ind+1, word, curr->next[c-'a']);
            
            else
                return false;
        }
        else
        {
            bool ans = false;
            for(int i=0; i<26; i++)
            {
                if(curr->next[i])
                {
                    ans = ans || backtrack(ind+1, word, curr->next[i]);
                }
            }
            return ans;
        }

    }
    bool search(string word) {
        TrieNode* curr = root;
        return backtrack(0, word, curr);
    }
};
