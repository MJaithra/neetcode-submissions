class Solution {
public:
    bool backtrack(int i, int j,int m, int n, int ind,  vector<vector<bool>> &used, vector<vector<char>>& board, string &word)
    {
        //base case
        if(ind == word.length())
        {
            return true;
        }

        if(i>=m || j>=n || i<0 || j<0)
        {
            return false;
        }

        
        if(!used[i][j] && word[ind] == board[i][j])
        {
            used[i][j] = true;
            bool found = backtrack(i+1, j, m, n, ind+1, used, board, word) ||
            backtrack(i, j+1, m, n, ind+1, used, board, word) || 
            backtrack(i-1, j, m, n, ind+1, used, board, word) ||
            backtrack(i, j-1, m, n, ind+1, used, board, word);
            used[i][j] = false;

            return found;
        }
        else
        {
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                bool found = backtrack(i, j, m, n, 0, used, board, word);
                if(found)
                    return true;
            }
        }
        return false;
    }
};
