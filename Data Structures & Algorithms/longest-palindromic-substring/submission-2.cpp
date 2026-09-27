class Solution {
public:
    // solve(l,r) -> is the substring s[l..r] a palindrome?
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1, start=0;
        for(int l=n-1; l>=0; l--)
        {
            for(int r=l; r<n; r++)
            {
                if(l==r)
                    dp[l][r] = true;
                else if(l+1==r)
                    dp[l][r] = (s[l] == s[r]);
                else
                    dp[l][r] = (s[l]==s[r]) && dp[l+1][r-1];
                
                if(dp[l][r] && (r-l+1) > maxLen)
                {
                    maxLen = r-l+1;
                    start = l;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
