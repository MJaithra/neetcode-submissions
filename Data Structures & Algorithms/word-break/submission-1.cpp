class Solution {
public:
    // memoization
    vector<vector<int>> dp;
    bool solve(int i,  int j, string &s, vector<string> & dict)
    {
        if(j >= s.length())
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
                
        string sub = s.substr(i, j-i+1);

        if(find(dict.begin(), dict.end(), sub) != dict.end())
        {
            if(j == s.length()-1)
                return dp[i][j] = true;

            return dp[i][j] = solve(j+1, j+1, s, dict) || solve(i, j+1, s, dict);
        }
        else
            return dp[i][j] = solve(i, j+1, s, dict);

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.resize(n, vector<int> (n, -1));
        return solve(0, 0, s, wordDict);
    }
};
