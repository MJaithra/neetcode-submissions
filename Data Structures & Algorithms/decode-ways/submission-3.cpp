class Solution {
public:
    // solve(i) -> number of ways to decode string starting at ind i
    // recursion - will give TLE
    int numDecodings(string s) {
        int n = s.length();
        int nxt1 = 1;
        int nxt2 = 1;
        int curr=0;
        for(int i=n-1; i>=0; i--)
        {
            curr=0;
             if(s[i] != '0')
                curr+=nxt1;
            
            if(i+1 < s.length() && (s[i] == '1' || (s[i]=='2' && s[i+1] <= '6')))
                curr+=nxt2;
            
            nxt2=nxt1;
            nxt1=curr;
        }
        return curr;
    }
};
