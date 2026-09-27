class Solution {
public:
    // solve(l,r) -> is the substring s[l..r] a palindrome?
    vector<vector<int>> dp;
    bool solve(int l, int r, string& s)
    {
        if(l == r)
            return true;
        
        if(l + 1 == r)
            return s[l] == s[r];

        if(dp[l][r] != -1)
            return dp[l][r];
        
        return dp[l][r] = (s[l]==s[r]) && solve(l+1, r-1, s);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        int maxLen = INT_MIN, start=0;
        for(int l=0; l<n; l++)
        {
            for(int r=l; r<n; r++)
            {
                if(solve(l,r,s))
                {
                    int len = r-l+1;
                    if(len > maxLen)
                    {
                        maxLen = len;
                        start = l;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
