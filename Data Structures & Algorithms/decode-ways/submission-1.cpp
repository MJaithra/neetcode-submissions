class Solution {
public:
    // solve(i) -> number of ways to decode string starting at ind i
    // recursion - will give TLE
    vector<int> dp;
    int solve(int i, string &s)
    {
        if(i >= s.length())
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int c1=0,c2=0;
        if(s[i] != '0')
            c1 = solve(i+1,s);
        
        if(i+1 < s.length() && (s[i] == '1' || (s[i]=='2' && s[i+1] <= '6')))
            c2 = solve(i+2,s);
        
        return dp[i]=c1+c2;

    }
    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return solve(0,s);
    }
};
