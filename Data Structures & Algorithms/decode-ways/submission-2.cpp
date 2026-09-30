class Solution {
public:
    // solve(i) -> number of ways to decode string starting at ind i
    // recursion - will give TLE
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+2,0);
        dp[n] = 1;
        dp[n+1] = 1;
        for(int i=n-1; i>=0; i--)
        {
             if(s[i] != '0')
                dp[i]+=dp[i+1];
            
            if(i+1 < s.length() && (s[i] == '1' || (s[i]=='2' && s[i+1] <= '6')))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};
