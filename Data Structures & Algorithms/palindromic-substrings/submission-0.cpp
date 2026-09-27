class Solution {
public:
    // solve(l, r) -> is the substring s[l..r] a palindrome
    vector<vector<int>> dp;
    bool solve(int l, int r, string& s)
    {
        if(l == r)
            return true;
        if(l+1==r)
            return dp[l][r] = (s[l] == s[r]);
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        return dp[l][r] = (s[l] == s[r]) && solve(l+1, r-1, s);
    }
    int countSubstrings(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n,-1));
        int ans=0;
        for(int l=0; l<n; l++)
        {
            for(int r=l; r<n; r++)
            {
                if(solve(l,r,s))
                    ans++;
            }
        }

        return ans;
    }
};
