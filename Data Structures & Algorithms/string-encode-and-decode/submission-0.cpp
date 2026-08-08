class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs)
        {
            res += to_string(s.length()) + "," + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        int ind=0;
        int len = s.length();
        vector<string> res;
        while(ind < len)
        {
            int cInd = s.find(",", ind);
            int size = stoi(s.substr(ind, cInd-ind));
            string r = s.substr(cInd+1, size);
            res.push_back(r);
            ind = cInd+1+size;
        }

        return res;
    }
};
