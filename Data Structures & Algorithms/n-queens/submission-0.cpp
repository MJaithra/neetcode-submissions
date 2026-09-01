class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;
    bool valid(int r, int c, vector<pair<int,int>> queens)
    {
        for(auto q : queens)
        {
            if(q.second == c)
                return false;
            
            if(abs(r-q.first) == abs(c-q.second))
                return false;
        }

        return true;
    }
    void backtrack(int row, vector<pair<int,int>> &queens, int &n)
    {
        if(row == n)
        {
            res.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++)
        {
            if(!valid(row,i,queens))
                continue;
            string l(n, '.');
            l[i]='Q';
            curr.push_back(l);
            queens.push_back({row,i});
            backtrack(row+1, queens, n);
            curr.pop_back();
            queens.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int,int>> queens;
        backtrack(0,queens,n);
        return res;
    }
};
