class Solution {
public:
    string curr;
    vector<string> res;
    vector<string> letters = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(int ind, string& digits)
    {
        if(ind == digits.length())
        {
            res.push_back(curr);
            return;
        }

        for( char c : letters[digits[ind] - '0'])
        {
            curr.push_back(c);
            backtrack(ind+1, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
            
        backtrack(0, digits);
        return res;
    }
};
