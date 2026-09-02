class Solution {
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

    void insert(string word, TrieNode* root)
    {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(!curr->next[c-'a'])
                curr->next[c-'a'] = new TrieNode();
            
            curr = curr->next[c-'a'];
        }

        curr->isEnd = true;
    }

    bool isBounded(int i, int j, int&m, int&n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }

    vector<string> res;
    string curr;
    void backtrack(int i, int j, int m, int n, vector<vector<bool>> &used, TrieNode* t, vector<vector<char>>& board)
    {
        curr.push_back(board[i][j]);
        used[i][j]=true;
        
        if(t->isEnd)
        {
            res.push_back(curr);
            t->isEnd = false;
        }

        if(isBounded(i+1,j, m, n) && !used[i+1][j] && t->next[board[i+1][j]-'a'])
            backtrack(i+1, j, m, n, used, t->next[board[i+1][j]-'a'], board);
        if(isBounded(i,j+1,m,n) && !used[i][j+1] && t->next[board[i][j+1]-'a'])
            backtrack(i, j+1, m, n, used, t->next[board[i][j+1]-'a'], board);
        if(isBounded(i-1,j,m,n) && !used[i-1][j] && t->next[board[i-1][j]-'a'])
            backtrack(i-1, j, m, n, used, t->next[board[i-1][j]-'a'], board);
        if(isBounded(i,j-1,m,n) && !used[i][j-1] && t->next[board[i][j-1]-'a'])
            backtrack(i, j-1, m, n, used, t->next[board[i][j-1]-'a'], board);
        
        curr.pop_back();
        used[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string w : words)
        {
            insert(w, root);
        }

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(root->next[board[i][j] - 'a'])
                {
                    backtrack(i, j, m, n, used, root->next[board[i][j] - 'a'], board);
                }
            }
        }

        return res;
    }
};
