class Solution {
public:
    vector<string> res;
    string curr;

    void backtrack(int open, int close, int &n)
    {
        if(open == n && close == n)
        {
            res.push_back(curr);
            return;
        }

        if(open < n)
        {
            curr.push_back('(');
            backtrack(open+1, close, n);
            curr.pop_back();
        }

        if(close < open)
        {
            curr.push_back(')');
            backtrack(open, close+1, n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};
