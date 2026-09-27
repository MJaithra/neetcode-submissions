class Solution {
public:
    // non dp solution
    int maxLen,start;
    void expand(int l, int r, string &s)
    {
        int n = s.length();
        while(l>=0 && r<n && s[l]==s[r])
        {
            int len = r-l+1;
            if(len > maxLen)
            {
                maxLen=len;
                start=l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        maxLen=1; 
        start=0;
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            expand(i, i, s);
            expand(i, i+1, s);
        }
        return s.substr(start, maxLen);
    }
};
