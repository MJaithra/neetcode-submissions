class Solution {
public:
    string makeSignature(string s)
    {
        vector<int> freq(26, 0);
        for(char c : s)
        {
            freq[c-'a']++;
        }

        string key = "";
        for(int i=0; i< 26; i++)
        {
            key += "#" + to_string(freq[i]);
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string s : strs)
        {
            string key = makeSignature(s);
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &entry : groups)
        {
            res.push_back(entry.second);
        }

        return res;
    }
};
