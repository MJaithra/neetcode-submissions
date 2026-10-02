class Solution {
public:
    // solve(i) -> can the suffix s[i...n-1] be completely broken into dictionary words?
    vector<int> dp;
    bool solve(int i,  string &s, unordered_set<string> &dict)
    {
        int n = s.length();

        if(i == n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
                
        for(int j =i; j<n; j++)
        {
            string sub = s.substr(i, j-i+1);
            if(dict.count(sub))
            {
                if(solve(j+1, s, dict))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.resize(n, -1);
        unordered_set<string> dict;
        for(auto w : wordDict)
        {
            dict.insert(w);
        }
        return solve(0, s, dict);
    }
};
