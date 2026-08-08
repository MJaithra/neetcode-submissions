class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {
            {'[',']'},
            {'(',')'},
            {'{','}'}
        };
        for(int i = 0; i<s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                
                char c = st.top();
                if(m[c] == s[i])
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};
