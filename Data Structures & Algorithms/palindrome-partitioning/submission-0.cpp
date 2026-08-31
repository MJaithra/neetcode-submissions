class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;
    bool isPalindrome(string s)
    {
        int len = s.length();
        for(int i=0; i<(len/2); i++)
        {
            if(s[i] != s[len - i -1])
                return false;
        }

        return true;
    }
    void backtrack(int start, string s)
    {
        if(start == s.length())
        {
            res.push_back(curr);
            return;
        }

        for(int end = start; end<s.length(); end++)
        {
            string sub = s.substr(start, end-start+1);
            if(isPalindrome(sub))
            {
                curr.push_back(sub);
                backtrack(end+1, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(0,s);
        return res;
    }
};
