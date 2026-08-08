class Solution {
public:
    bool isValid(unordered_map<char, int> &m1,unordered_map<char, int> &m2 )
    {
        for(const auto& [key, value]: m2)
        {
            if(m1[key] < value)
                return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> freqs;
        unordered_map<char, int> freqt;

        for(int i=0; i<t.length(); i++)
        {
            freqt[t[i]]++;
        }

        int left=0, len=INT_MAX;
        string res="";
        for(int right=0; right<s.length(); right++)
        {
            freqs[s[right]]++;
            while(isValid(freqs, freqt))
            {
                res = len > right-left+1 ? s.substr(left, right-left+1) : res;
                len = min(len, right-left+1);
                freqs[s[left]]--;
                left++;
            }
        }

        return res;
    }
};
