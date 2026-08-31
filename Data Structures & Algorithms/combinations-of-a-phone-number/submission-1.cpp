class Solution {
public:
    string curr;
    vector<string> res;
    unordered_map<char,vector<char>> mp = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}},
    };
    void backtrack(int ind, string& digits)
    {
        if(ind == digits.length() && curr.length()>0)
        {
            res.push_back(curr);
            return;
        }

        for( int i=0; i<mp[digits[ind]].size(); i++)
        {
            curr.push_back(mp[digits[ind]][i]);
            backtrack(ind+1, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backtrack(0, digits);
        return res;
    }
};
